// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Commons/Tags.hpp>
#include <PokeMaster/Components/Index.hpp>
#include <PokeMaster/Components/Level.hpp>
#include <PokeMaster/Components/Name.hpp>
#include <PokeMaster/Components/Natures.hpp>
#include <PokeMaster/Components/Stats.hpp>
#include <PokeMaster/Components/Types.hpp>
#include <PokeMaster/Helpers/PokemonHelpers.hpp>

#include <json/json.hpp>

#include <fstream>

namespace PokeMaster::Pokemon
{
void LoadData(entt::registry& registry)
{
    // Read pokemon related data from JSON file
    std::ifstream pokemonFile(RESOURCES_DIR "pokemon.json");
    std::ifstream pokemonStatsFile(RESOURCES_DIR "pokemon_stats.json");
    std::ifstream pokemonTypesFile(RESOURCES_DIR "pokemon_types.json");

    nlohmann::json pokemonJSON, pokemonStatsJSON, pokemonTypesJSON;
    pokemonFile >> pokemonJSON;
    pokemonStatsFile >> pokemonStatsJSON;
    pokemonTypesFile >> pokemonTypesJSON;

    for (auto& pokemon : pokemonJSON)
    {
        auto index = pokemon["id"].get<int>();

        Type type1 = Type::INVALID;
        Type type2 = Type::INVALID;

        for (auto& type : pokemonTypesJSON)
        {
            auto pokemonID = type["pokemon_id"].get<int>();

            if (pokemonID < index)
            {
                continue;
            }
            else if (pokemonID > index)
            {
                break;
            }
            else
            {
                if (type["slot"].get<int>() == 1)
                {
                    type1 = static_cast<Type>(type["type_id"].get<int>());
                }
                else
                {
                    type2 = static_cast<Type>(type["type_id"].get<int>());
                }
            }
        }

        StatStorage baseStats;

        for (auto& stat : pokemonStatsJSON)
        {
            auto pokemonID = stat["pokemon_id"].get<int>();

            if (pokemonID < index)
            {
                continue;
            }
            else if (pokemonID > index)
            {
                break;
            }
            else
            {
                baseStats[stat["stat_id"].get<int>() - 1] = stat["base_stat"].get<int>();
            }
        }

        auto entity = registry.create();
        registry.emplace<Tag::Pokemon>(entity);
        registry.emplace<Index>(entity, index);
        registry.emplace<Name>(entity, pokemon["identifier"].get<std::string>());
        registry.emplace<Types>(entity, type1, type2);
        registry.emplace<Stats>(entity, baseStats);
    }

    pokemonFile.close();
    pokemonStatsFile.close();
    pokemonTypesFile.close();
}

entt::entity Add(entt::registry& registry, std::string_view&& name, int level,
                 StatStorage individualValues, StatStorage effortValues, Nature nature)
{
    entt::entity pokemon = FindByName(registry, std::move(name)).value();
    entt::entity newPokemon = registry.create();

    auto view = registry.view<Name, Types, Stats>();
    auto& pokemonName = view.get<Name>(pokemon);
    auto& pokemonTypes = view.get<Types>(pokemon);
    auto& pokemonStats = view.get<Stats>(pokemon);

    registry.emplace<Tag::PlayerPokemon>(newPokemon);
    registry.emplace<Name>(newPokemon, pokemonName.name);
    registry.emplace<Level>(newPokemon, level);
    registry.emplace<Types>(newPokemon, pokemonTypes.type1, pokemonTypes.type2);
    registry.emplace<Stats>(newPokemon, pokemonStats.baseValues, individualValues,
                            effortValues);
    registry.emplace<Natures>(newPokemon, nature);

    CalculateStats(registry, newPokemon);

    return newPokemon;
}

void CalculateStats(entt::registry& registry, entt::entity entity)
{
    auto view = registry.view<Level, Stats, Natures>();
    auto& level = view.get<Level>(entity);
    auto& stats = view.get<Stats>(entity);
    auto& natures = view.get<Natures>(entity);

    const auto iter = std::find_if(std::begin(NATURES), std::end(NATURES),
                                   [=](const std::tuple<Nature, Stat, Stat>& val) {
                                       return natures.nature == std::get<0>(val);
                                   });
    const Stat increasedStat = std::get<1>(*iter);
    const Stat decreasedStat = std::get<2>(*iter);

    // Formula
    // HP = floor(0.01 x (2 x Base + IV + floor(0.25 x EV)) x Level) + Level + 10
    stats.values[Stat::HP] = static_cast<int>(
        std::floor(0.01 *
                   (2 * stats.baseValues[Stat::HP] + stats.individualValues[Stat::HP] +
                    std::floor(0.25 * stats.effortValues[Stat::HP])) *
                   level.level) +
        level.level + 10);
    // Other Stats = (floor(0.01 x (2 x Base + IV + floor(0.25 x EV)) x Level) + 5)
    //               x Nature
    for (std::size_t i = 1; i < 6; i++)
    {
        const Stat convertedStat = static_cast<Stat>(i + 1);
        const double natureRatio = increasedStat == convertedStat   ? 1.1
                                   : decreasedStat == convertedStat ? 0.9
                                                                    : 1.0;

        stats.values[i] = static_cast<int>(
            (std::floor(0.01 *
                        (2 * stats.baseValues[i] + stats.individualValues[i] +
                         std::floor(0.25 * stats.effortValues[i])) *
                        level.level) +
             5) *
            natureRatio);
    }
}

std::optional<entt::entity> FindByName(entt::registry& registry, std::string_view&& name)
{
    const auto view = registry.view<Name>();

    for (auto [entity, pokemonName] : view.each())
    {
        if (name == pokemonName.name)
        {
            return entity;
        }
    }

    return std::nullopt;
}

std::tuple<Type, Type> GetTypes(entt::registry& registry, entt::entity entity)
{
    auto view = registry.view<Types>();
    auto& types = view.get<Types>(entity);

    return std::make_tuple(types.type1, types.type2);
}

StatStorage GetStats(entt::registry& registry, entt::entity entity)
{
    if (!registry.all_of<Tag::PlayerPokemon>(entity))
    {
        return StatStorage{};
    }

    auto stats = registry.get<Stats>(entity);
    return stats.values;
}
}  // namespace PokeMaster::Pokemon