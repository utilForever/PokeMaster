// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Components/Name.hpp>
#include <PokeMaster/Helpers/ItemHelpers.hpp>
#include <PokeMaster/Helpers/MoveHelpers.hpp>
#include <PokeMaster/Helpers/PokemonHelpers.hpp>
#include <PokeMaster/Systems/Game.hpp>

#include <utility>

namespace PokeMaster
{
Game::Game()
{
    Pokemon::LoadData(m_registry);
    Move::LoadData(m_registry);
    Item::LoadData(m_registry);
}

entt::entity Game::AddPokemon(std::string_view name, int level,
                              std::array<int, NUM_STATS> individualValues,
                              std::array<int, NUM_STATS> effortValues, Nature nature)
{
    return Pokemon::Add(m_registry, std::move(name), level, individualValues,
                        effortValues, nature);
}

std::optional<entt::entity> Game::FindPokemonByName(std::string_view&& name)
{
    return Pokemon::FindByName(m_registry, std::move(name));
}

std::tuple<Type, Type> Game::GetPokemonTypes(entt::entity entity)
{
    return Pokemon::GetTypes(m_registry, entity);
}
}  // namespace PokeMaster