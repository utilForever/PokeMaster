// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_ENUMS_HPP
#define POKEMASTER_POKEMON_ENUMS_HPP

namespace PokeMaster
{
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
//! Second digit of nature Code indicates a stat which will be decreased by 10%.
//! Numbers 1~5 correspond to ATTACK, DEFENSE, SPECIAL_ATTACK, SPECIAL_DEFENSE
//! and SPEED.
enum class Nature
{
    INVALID,
    ADAMANT = 13,  //!      +ATTACK            -SPECIAL_ATTACK
    BASHFUL = 0,
    BOLD = 21,     //!      +DEFENSE           -ATTACK
    BRAVE = 15,    //!      +ATTACK            -SPEED
    CALM = 41,     //!      +SPECIAL_DEFENSE   -ATTACK
    CAREFUL = 43,  //!      +SPECIAL_DEFENSE   -SPECIAL_ATTACK
    DOCILE = 0,
    GENTLE = 42,  //!      +SPECIAL_DEFENSE   -DEFENSE
    HARDY = 0,
    HASTY = 52,    //!      +SPEED             -DEFENSE
    IMPISH = 23,   //!      +DEFENSE           -SPECIAL_ATTACK
    JOLLY = 53,    //!      +SPEED             -SPECIAL_ATTACK
    LAX = 24,      //!      +DEFENSE           -SPECIAL_DEFENSE
    LONELY = 12,   //!      +ATTACK            -DEFENSE
    MILD = 32,     //!      +SPECIAL_ATTACK    -DEFENSE
    MODEST = 31,   //!      +SPECIAL_ATTACK    -ATTACK
    NAIVE = 54,    //!      +SPEED             -SPECIAL_DEFENSE
    NAUGHTY = 14,  //!      +ATTACK            -SPECIAL_DEFENSE
    QUIET = 35,    //!      +SPECIAL_ATTACK    -SPEED
    QUIRKY = 0,
    RASH = 34,     //!      +SPECIAL_ATTACK    -SPECIAL_DEFENSE
    RELAXED = 25,  //!      +DEFENSE           -SPEED
    SASSY = 45,    //!      +SPECIAL_DEFENSE   -SPEED
    SERIOUS = 0,
    TIMID = 52  //!      +SPEED             -ATTACK
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
