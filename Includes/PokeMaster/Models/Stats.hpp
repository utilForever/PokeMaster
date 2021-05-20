// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_STATS_HPP
#define POKEMASTER_STATS_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>

#include <array>
#include <initializer_list>

namespace PokeMaster
{
//!
//! \brief Stats class.
//!
//! A statistic (Japanese: 能力 ability), or stat for short, is an element which
//! determines certain aspects of battles in the games. Stats may also refer to the
//! numerical values of each field in regards to individual Pokémon.
//!
class Stats
{
 public:
    //! Default constructor.
    Stats() = default;

    //! Constructs with given \p stats.
    //! \param stats A list of stats.
    Stats(std::initializer_list<int> stats);

    //! Operator overloading: operator[] with given \p idx.
    //! \param idx The index of stat list.
    //! \return The value of stat at \p idx.
    int& operator[](std::size_t idx) noexcept;

    //! Operator overloading: operator[] with given \p stat.
    //! \param stat The stat to get the value.
    //! \return The value of \p stat.
    int& operator[](Stat stat) noexcept;

 private:
    std::array<int, 6> m_stats{};
};
}  // namespace PokeMaster

#endif  // POKEMASTER_STATS_HPP
