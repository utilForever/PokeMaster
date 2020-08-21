// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Managers/PokemonManager.hpp>

using namespace PokeMaster;

TEST_CASE("[PokemonManager] - GetAllPokemons")
{
    auto pokemons = PokemonManager::GetInstance().GetAllPokemons();
    for (auto& pokemon : pokemons)
    {
        CHECK_NE(pokemon.GetID(), 0);
        CHECK_FALSE(pokemon.GetName().empty());
    }
}