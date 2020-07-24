// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_CONSTANTS_HPP
#define POKEMASTER_CONSTANTS_HPP

namespace PokeMaster
{
//! The number of pokemons.
constexpr int NUM_POKEMONS = 964;

//! The number of moves.
constexpr int NUM_MOVES = 746;

//! The number of abilities.
constexpr int NUM_ABILITIES = 293;

//! The number of items.
constexpr int NUM_ITEMS = 954;

enum Type
    {
        NORMAL = 1,
        FIGHTING,
        FLYING,
        POISON,
        GROUND,
        ROCK,
        BUG,
        GHOST,
        STEEL,
        FIRE,
        WATER,
        GRASS,
        ELECTRIC,
        PSYCHIC,
        ICE,
        DRAGON,
        DARK,
        FAIRY,
        UNKNOWN,
        SHADOW
    };

enum DamageClass
    {
        STATUS = 1,
        PHYSICAL,
        SPECIAL
    };

}  // namespace PokeMaster

#endif  // POKEMASTER_CONSTANTS_HPP
