// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Pokemon.hpp>

#include <cmath>

namespace PokeMaster
{
Pokemon::Pokemon(int id, std::string_view name) : m_id(id), m_name(name)
{
    // Do nothing
}

int Pokemon::GetID() const
{
    return m_id;
}

std::string_view Pokemon::GetName() const
{
    return m_name;
}

Type Pokemon::GetType1() const
{
    return m_type1;
}

Type Pokemon::GetType2() const
{
    return m_type2;
}

int Pokemon::GetLevel() const
{
    return m_level;
}

Stats Pokemon::GetStats() const
{
    return m_stats;
}

Nature Pokemon::GetNature() const
{
    return m_nature;
}

Ability Pokemon::GetAbility() const
{
    return m_ability;
}

std::optional<Item> Pokemon::GetItem() const
{
    return m_item;
}

Status Pokemon::GetStatus() const
{
    return m_status;
}

std::array<std::optional<Move>, 4> Pokemon::GetMoves() const
{
    return m_moves;
}

void Pokemon::CalcStats()
{
    CalcHP();
    CalcOtherStats();
}

void Pokemon::CalcHP()
{
    m_stats[Stat::HP] =
        static_cast<int>(std::floor(((m_bases[Stat::HP] * 2) + m_ivs[Stat::HP] +
                                     std::floor(m_evs[Stat::HP] / 4)) *
                                    m_level / 100)) +
        m_level + 10;

    // For 'Shedinja' (Always HP is 1)
    if (m_bases[Stat::HP] == 1)
    {
        m_stats[Stat::HP] = 1;
    }
}

void Pokemon::CalcOtherStats()
{
    const auto iter = std::find_if(std::begin(NATURES), std::end(NATURES),
                                   [=](const std::tuple<Nature, Stat, Stat>& val) {
                                       return m_nature == std::get<0>(val);
                                   });
    const Stat natureStat1 = std::get<1>(*iter);
    const Stat natureStat2 = std::get<2>(*iter);

    for (std::size_t i = 1; i < 6; i++)
    {
        const Stat localStat = static_cast<Stat>(m_stats[i]);
        const double nature =
            natureStat1 == localStat ? 1.1 : natureStat2 == localStat ? 0.9 : 1.0;

        m_stats[i] = static_cast<int>(std::floor(
            (std::floor(((m_bases[i] * 2) + m_ivs[i] + std::floor(m_evs[i] / 4)) *
                        m_level / 100) +
             5) *
            nature));
    }
}
}  // namespace PokeMaster