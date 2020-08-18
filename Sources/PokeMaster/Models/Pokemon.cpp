// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Models/Pokemon.hpp>

#include <cmath>

namespace PokeMaster
{
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

//! ID, Name, Getter & Setter Functions.
int Pokemon::GetId()
{
    return m_id;
}
std::string_view Pokemon::GetName()
{
    return m_name;
}
int Pokemon::GetLevel()
{
    return m_level;
}
Nature Pokemon::GetNature()
{
    return m_nature;
}
std::array<int, 6> Pokemon::GetBases()
{
    return m_bases;
}
std::array<int, 6> Pokemon::GetIvs()
{
    return m_ivs;
}
std::array<int, 6> Pokemon::GetEvs()
{
    return m_evs;
}
std::array<int, 6> Pokemon::GetStats()
{
    return m_stats;
}
Item Pokemon::GetItem()
{
    return m_item;
}
Ability Pokemon::GetAbility()
{
    return m_ability;
}
std::array<std::optional<Move>, 4> Pokemon::GetMoves()
{
    return m_moves;
}
Status Pokemon::GetStatus()
{
    return m_status;
}

void Pokemon::SetId(int _id)
{
    m_id = _id;
}
void Pokemon::SetName(std::string_view _name)
{
    m_name = _name;
}
void Pokemon::SetLevel(int _level)
{
    m_level = _level;
}
void Pokemon::SetNature(Nature _nature)
{
    m_nature = _nature;
}
void Pokemon::SetBases(std::array<int, 6> _bases)
{
    for (int i = 0; i < 6; i++)
    {
        m_bases[i] = _bases[i];
    }
}
void Pokemon::SetIvs(std::array<int, 6> _ivs)
{
    for (int i = 0; i < 6; i++)
    {
        m_ivs[i] = _ivs[i];
    }
}
void Pokemon::SetEvs(std::array<int, 6> _evs)
{
    for (int i = 0; i < 6; i++)
    {
        m_evs[i] = _evs[i];
    }
}
void Pokemon::SetStats(std::array<int, 6> _stats)
{
    for (int i = 0; i < 6; i++)
    {
        m_stats[i] = _stats[i];
    }
}
void Pokemon::SetItem(Item _item)
{
    m_item = _item;
}
void Pokemon::SetAbility(Ability _ability)
{
    m_ability = _ability;
}
void Pokemon::SetMoves(std::array<std::optional<Move>, 4> _moves)
{
    for (int i = 0; i < 6; i++)
    {
        m_moves[i] = _moves[i];
    }
}
void Pokemon::SetStatus(Status _status)
{
    m_status = _status;
}

//! Calculate stats with Base, IV, EV, Level, and Nature.
void Pokemon::CalcStats(std::array<int, 6> _bases, std::array<int, 6> _ivs,
                        std::array<int, 6> _evs, int _level, int _nature)
{
    CalcHP(_bases[0], _ivs[0], _evs[0], _level);
    CalcOtherStats(_bases, _ivs, _evs, _level, _nature);
}

}  // namespace PokeMaster