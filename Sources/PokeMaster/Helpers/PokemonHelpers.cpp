// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Components/Name.hpp>
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

    for (auto& data : pokemonJSON)
    {
        auto entity = registry.create();
        registry.emplace<Name>(entity, data["identifier"].get<std::string>());
    }

    pokemonFile.close();
    pokemonStatsFile.close();
    pokemonTypesFile.close();
}
}  // namespace PokeMaster::Pokemon