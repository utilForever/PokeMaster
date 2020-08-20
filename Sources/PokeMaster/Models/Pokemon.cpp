// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

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

std::array<int, 6> Pokemon::GetStats() const
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

//! Calculate HP of Pokemon with Base, IV, EV, Level.
void Pokemon::CalcHP(int _base, int _iv, int _ev, int _level)
{
    m_stats[0] =
        (int)floor(((_base * 2) + _iv + (_ev / 4)) * _level / 100) + 10;
    if (_base == 1)
    {
        m_stats[0] = 1;
    }  //! For Shedinja (Always has HP 1)
}

//! Calculate stats (except HP) of Pokemon with Base, IV, EV, Level, Nature.
void Pokemon::CalcOtherStats(std::array<int, 6> _bases, std::array<int, 6> _ivs,
                             std::array<int, 6> _evs, int _level, int _nature)
{
    for (int i = 1; i < 6; i++)
    {
        m_stats[i] = (int)floor(((_bases[i] * 2) + _ivs[i] + (_evs[i] / 4)) *
                                _level / 100) +
                     5;
    }

    //! Modifies stats by Nature.
    int stat_inc = (int)(_nature / 10);
    int stat_dec = (int)(_nature % 10);
    m_stats[stat_inc] = (int)floor(m_stats[stat_inc] * 1.1);
    m_stats[stat_dec] = (int)floor(m_stats[stat_dec] * 0.9);
}

//! Calculate stats with Base, IV, EV, Level, and Nature.
void Pokemon::CalcStats(std::array<int, 6> _bases, std::array<int, 6> _ivs,
                        std::array<int, 6> _evs, int _level, int _nature)
{
    CalcHP(_bases[0], _ivs[0], _evs[0], _level);
    CalcOtherStats(_bases, _ivs, _evs, _level, _nature);
}

}  // namespace PokeMaster