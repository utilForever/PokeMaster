// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_STATS_HPP
#define POKEMASTER_STATS_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Enums/PokemonEnums.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief Stats struct.
//!
//! A statistic (Japanese: 能力 ability), or stat for short, is an element which
//! determines certain aspects of battles in the games. Stats may also refer to the
//! numerical values of each field in regards to individual Pokémon.
//!
struct Stats
{
    std::array<int, NUM_STATS> m_baseValues;
    std::array<int, NUM_STATS> m_individualValues;
    std::array<int, NUM_STATS> m_effortValues;
    std::array<int, NUM_STATS> m_values;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_STATS_HPP
