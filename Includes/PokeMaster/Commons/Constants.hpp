// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_CONSTANTS_HPP
#define POKEMASTER_CONSTANTS_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>

#include <array>
#include <tuple>

namespace PokeMaster
{
//! The number of pokemons.
constexpr int NUM_POKEMONS = 964;

//! The number of natures.
constexpr int NUM_NATURES = 25;

//! The number of moves.
constexpr int NUM_MOVES = 746;

//! The number of items.
constexpr int NUM_ITEMS = 954;

//! A list of natures.
inline std::array<std::tuple<Nature, Stat, Stat>, NUM_NATURES> NATURES = {
    std::make_tuple(Nature::HARDY, Stat::INVALID, Stat::INVALID),
    std::make_tuple(Nature::BOLD, Stat::DEFENSE, Stat::ATTACK),
    std::make_tuple(Nature::MODEST, Stat::SPECIAL_ATTACK, Stat::ATTACK),
    std::make_tuple(Nature::CALM, Stat::SPECIAL_DEFENSE, Stat::ATTACK),
    std::make_tuple(Nature::TIMID, Stat::SPEED, Stat::ATTACK),
    std::make_tuple(Nature::LONELY, Stat::ATTACK, Stat::DEFENSE),
    std::make_tuple(Nature::DOCILE, Stat::INVALID, Stat::INVALID),
    std::make_tuple(Nature::MILD, Stat::SPECIAL_ATTACK, Stat::DEFENSE),
    std::make_tuple(Nature::GENTLE, Stat::SPECIAL_DEFENSE, Stat::DEFENSE),
    std::make_tuple(Nature::HASTY, Stat::SPEED, Stat::DEFENSE),
    std::make_tuple(Nature::ADAMANT, Stat::ATTACK, Stat::SPECIAL_ATTACK),
    std::make_tuple(Nature::IMPISH, Stat::DEFENSE, Stat::SPECIAL_ATTACK),
    std::make_tuple(Nature::BASHFUL, Stat::INVALID, Stat::INVALID),
    std::make_tuple(Nature::CAREFUL, Stat::SPECIAL_DEFENSE, Stat::SPECIAL_ATTACK),
    std::make_tuple(Nature::RASH, Stat::SPECIAL_ATTACK, Stat::SPECIAL_DEFENSE),
    std::make_tuple(Nature::JOLLY, Stat::SPEED, Stat::SPECIAL_ATTACK),
    std::make_tuple(Nature::NAUGHTY, Stat::ATTACK, Stat::SPECIAL_DEFENSE),
    std::make_tuple(Nature::LAX, Stat::DEFENSE, Stat::SPECIAL_DEFENSE),
    std::make_tuple(Nature::QUIRKY, Stat::INVALID, Stat::INVALID),
    std::make_tuple(Nature::NAIVE, Stat::SPEED, Stat::SPECIAL_DEFENSE),
    std::make_tuple(Nature::BRAVE, Stat::ATTACK, Stat::SPEED),
    std::make_tuple(Nature::RELAXED, Stat::DEFENSE, Stat::SPEED),
    std::make_tuple(Nature::QUIET, Stat::SPECIAL_ATTACK, Stat::SPEED),
    std::make_tuple(Nature::SASSY, Stat::SPECIAL_DEFENSE, Stat::SPEED),
    std::make_tuple(Nature::SERIOUS, Stat::INVALID, Stat::INVALID)
};
}  // namespace PokeMaster

#endif  // POKEMASTER_CONSTANTS_HPP
