// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Models/Stats.hpp>

#include <cassert>

namespace PokeMaster
{
Stats::Stats(std::initializer_list<int> stats)
{
    assert(stats.size() == 6);

    std::size_t idx = 0;
    for (const auto& stat : stats)
    {
        m_stats[idx] = stat;
        ++idx;
    }
}

int& Stats::operator[](std::size_t idx) noexcept
{
    return m_stats[idx];
}

int& Stats::operator[](Stat stat) noexcept
{
    return m_stats[static_cast<std::size_t>(stat) - 1];
}
}  // namespace PokeMaster
