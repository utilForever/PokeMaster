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
#include <cassert>

namespace PokeMaster
{
//!
//! \brief StatStorage class.
//!
//! A simple storage class for struct Stats.
//!
class StatStorage
{
 public:
    StatStorage() = default;

    explicit StatStorage(std::initializer_list<int> stats)
    {
        assert(stats.size() == 6);

        std::size_t idx = 0;
        for (const auto& stat : stats)
        {
            m_values[idx] = stat;
            ++idx;
        }
    }

    int& operator[](std::size_t idx) noexcept
    {
        return m_values[idx];
    }

    int& operator[](Stat stat) noexcept
    {
        return m_values[static_cast<std::size_t>(stat) - 1];
    }

 private:
    std::array<int, NUM_STATS> m_values;
};

//!
//! \brief Stats struct.
//!
//! A statistic (Japanese: 能力 ability), or stat for short, is an element which
//! determines certain aspects of battles in the games. Stats may also refer to the
//! numerical values of each field in regards to individual Pokémon.
//!
//! Base statistics are the statistics a Pokémon has when it is born.
//! These increase when the Pokémon wins in a battle and levels up.
//!
//! Individual Values, or IVs, serve as a factor in determining a Pokémon's stats
//! and differ from Pokémon to Pokémon, functioning like a Pokémon's "Genes".
//!
//! Effort Value Points (or EVs) are unseen statistics that can increase your
//! Pokémon's stats. The system was introduced in the third generation (Ruby,
//! Sapphire and Emerald). EVs are obtained by fighting other Pokémon.
//! Depending on the defeated Pokémon, different EVs will be obtained.
//!
struct Stats
{
    StatStorage baseValues;
    StatStorage individualValues;
    StatStorage effortValues;
    StatStorage values;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_STATS_HPP
