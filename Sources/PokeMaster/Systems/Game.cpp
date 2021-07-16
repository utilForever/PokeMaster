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

namespace PokeMaster
{
Game::Game()
{
    Pokemon::LoadData(m_registry);
    Move::LoadData(m_registry);
    Item::LoadData(m_registry);
}

std::optional<entt::entity> Game::FindPokemonByName(std::string_view&& name)
{
    const auto view = m_registry.view<Name>();

    for (auto [entity, pokemonName] : view.each())
    {
        if (name == pokemonName.name)
        {
            return entity;
        }
    }

    return std::nullopt;
}
}  // namespace PokeMaster