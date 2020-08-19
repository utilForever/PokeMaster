// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_ENUMS_HPP
#define POKEMASTER_POKEMON_ENUMS_HPP

namespace PokeMaster
{
//! Pokemon types.
enum class Type
{
    INVALID,
    NORMAL,
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
    FAIRY
};

//! Pokemon stats.
enum class Stat
{
    HP,
    ATTACK,
    DEFENSE,
    SPECIAL_ATTACK,
    SPECIAL_DEFENSE,
    SPEED
};

//! Pokemon natures.
//! First digit of nature code indicates a stat which will be increased by 10%.
//! Second digit of nature code indicates a stat which will be decreased by 10%.
//! Numbers 1~5 correspond to ATTACK, DEFENSE, SPECIAL_ATTACK, SPECIAL_DEFENSE
//! and SPEED.
enum class Nature
{
    INVALID,
    HARDY,
    BOLD,
    MODEST,
    CALM,
    TIMID,
    LONELY,
    DOCILE,
    MILD,
    GENTLE,
    HASTY,
    ADAMANT,
    IMPISH,
    BASHFUL,
    CAREFUL,
    RASH,
    JOLLY,
    NAUGHTY,
    LAX,
    QUIRKY,
    NAIVE,
    BRAVE,
    RELAXED,
    QUIET,
    SASSY,
    SERIOUS
};

//! Pokemon status.
enum class Status
{
    NORMAL,
    HEALTHY,
    POISONED,
    BADLY_POISONED,
    BURNED,
    PARALYZED,
    ASLEEP,
    FROZEN
};
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
