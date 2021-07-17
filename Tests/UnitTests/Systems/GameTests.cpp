// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Systems/Game.hpp>

using namespace PokeMaster;

TEST_CASE("[Game] - FindPokemonByIndex")
{
    Game game;

    {
        auto pokemon = game.FindPokemonByIndex(1);
        CHECK_EQ(pokemon.has_value(), true);
    }

    {
        auto pokemon = game.FindPokemonByIndex(-1);
        CHECK_EQ(pokemon.has_value(), false);
    }
}

TEST_CASE("[Game] - FindPokemonByName")
{
    Game game;

    {
        auto pokemon = game.FindPokemonByName("bulbasaur");
        CHECK_EQ(pokemon.has_value(), true);
    }

    {
        auto pokemon = game.FindPokemonByName("test");
        CHECK_EQ(pokemon.has_value(), false);
    }
}

TEST_CASE("[Game] - GetPokemonLevel")
{
    Game game;

    {
        auto pokemon =
            game.AddPokemon("bulbasaur", 50, StatStorage{ 31, 31, 31, 31, 31, 31 },
                            StatStorage{ 252, 4, 0, 252, 0, 0 }, Nature::QUIET);
        auto level = game.GetPokemonLevel(pokemon);
        CHECK_EQ(level, 50);
    }

    {
        auto pokemon =
            game.AddPokemon("dragonair", 24, StatStorage{ 15, 24, 8, 18, 23, 29 },
                            StatStorage{ 0, 0, 252, 4, 252, 0 }, Nature::HARDY);
        auto level = game.GetPokemonLevel(pokemon);
        CHECK_EQ(level, 24);
    }
}

TEST_CASE("[Game] - GetPokemonTypes")
{
    Game game;

    {
        auto pokemon = game.FindPokemonByName("bulbasaur");
        CHECK_EQ(pokemon.has_value(), true);

        auto [type1, type2] = game.GetPokemonTypes(pokemon.value());
        CHECK_EQ(type1, Type::GRASS);
        CHECK_EQ(type2, Type::POISON);
    }

    {
        auto pokemon = game.FindPokemonByName("dragonair");
        CHECK_EQ(pokemon.has_value(), true);

        auto [type1, type2] = game.GetPokemonTypes(pokemon.value());
        CHECK_EQ(type1, Type::DRAGON);
        CHECK_EQ(type2, Type::INVALID);
    }
}

TEST_CASE("[Game] - GetPokemonStats")
{
    Game game;

    {
        auto pokemon =
            game.AddPokemon("bulbasaur", 50, StatStorage{ 31, 31, 31, 31, 31, 31 },
                            StatStorage{ 252, 4, 0, 252, 0, 0 }, Nature::QUIET);
        auto stats = game.GetPokemonStats(pokemon);
        CHECK_EQ(stats[Stat::HP], 152);
        CHECK_EQ(stats[Stat::ATTACK], 70);
        CHECK_EQ(stats[Stat::DEFENSE], 69);
        CHECK_EQ(stats[Stat::SPECIAL_ATTACK], 128);
        CHECK_EQ(stats[Stat::SPECIAL_DEFENSE], 85);
        CHECK_EQ(stats[Stat::SPEED], 58);
    }

    {
        auto pokemon =
            game.AddPokemon("dragonair", 24, StatStorage{ 15, 24, 8, 18, 23, 29 },
                            StatStorage{ 0, 0, 252, 4, 252, 0 }, Nature::HARDY);
        auto stats = game.GetPokemonStats(pokemon);
        CHECK_EQ(stats[Stat::HP], 66);
        CHECK_EQ(stats[Stat::ATTACK], 51);
        CHECK_EQ(stats[Stat::DEFENSE], 53);
        CHECK_EQ(stats[Stat::SPECIAL_ATTACK], 43);
        CHECK_EQ(stats[Stat::SPECIAL_DEFENSE], 59);
        CHECK_EQ(stats[Stat::SPEED], 45);
    }

    {
        auto pokemon = game.FindPokemonByName("bulbasaur");
        auto stats = game.GetPokemonStats(pokemon.value());
        CHECK_EQ(stats[Stat::HP], 45);
        CHECK_EQ(stats[Stat::ATTACK], 49);
        CHECK_EQ(stats[Stat::DEFENSE], 49);
        CHECK_EQ(stats[Stat::SPECIAL_ATTACK], 65);
        CHECK_EQ(stats[Stat::SPECIAL_DEFENSE], 65);
        CHECK_EQ(stats[Stat::SPEED], 45);
    }
}