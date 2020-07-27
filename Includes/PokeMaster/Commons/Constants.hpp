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

enum Types
    {
        NORMAL = 1,     // 1
        FIGHTING,       // 2
        FLYING,         // 3
        POISON,         // 4
        GROUND,         // 5
        ROCK,           // 6
        BUG,            // 7
        GHOST,          // 8
        STEEL,          // 9
        FIRE,           // 10
        WATER,          // 11
        GRASS,          // 12
        ELECTRIC,       // 13
        PSYCHIC,        // 14
        ICE,            // 15
        DRAGON,         // 16
        DARK,           // 17
        FAIRY,          // 18
        UNKNOWN,        // 19
        SHADOW          // 20
    };

enum DamageClass
    {
        STATUS = 1,     // 1
        PHYSICAL,       // 2
        SPECIAL         // 3
    };

enum TargetTypes
    {
        SPECIFIC_MOVE = 1,          // 1
        SELECTED_POKEMON_ME_FIRST,  // 2
        ALLY,                       // 3
        USERS_FIELD,                // 4
        OPPONENTS_FIELD,            // 5
        USER,                       // 6
        RANDOM_OPPONENT,            // 7
        ALL_OTHER_POKEMON,          // 8
        SELECTED_POKEMON,           // 9
        ALL_OPPONENTS,              // 10
        ENTIRE_FIELD,               // 11
        USER_AND_ALLIES,            // 12
        ALL_POKEMON                 // 13
    };

}  // namespace PokeMaster

#endif  // POKEMASTER_CONSTANTS_HPP
