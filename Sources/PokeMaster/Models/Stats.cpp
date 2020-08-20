// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Models/Stats.hpp>

namespace PokeMaster
{
int& Stats::operator[](std::size_t idx) noexcept
{
    return m_stats[idx];
}

int& Stats::operator[](Stat stat) noexcept
{
    return m_stats[static_cast<std::size_t>(stat) - 1];
}
}  // namespace PokeMaster
