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
void Pokemon::CalcHP(int _base, int _iv, int _ev, int _level) {
	stats[0] = (int) floor(((_base * 2) + _iv + (_ev / 4)) * _level / 100) + 10;
	if (_base == 1) { stats[0] = 1; } //! For Shedinja (Always has HP 1)
}

//! Calculate stats (except HP) of Pokemon with Base, IV, EV, Level, Nature.
void Pokemon::CalcOtherStats(
  std::array<std::optional<int>, 6> _bases,
  std::array<std::optional<int>, 6> _ivs,
  std::array<std::optional<int>, 6> _evs,
  int _level, int _nature) {
	for (int i=1; i<6; i++) {
		stats[i] = (int) floor(((*_bases[i] * 2) + *_ivs[i] + (*_evs[i] / 4)) * _level / 100) + 5;
	}

	//! Modifies stats by Nature.
	int stat_inc = (int) (_nature / 10);
	int stat_dec = (int) (_nature % 10);
	stats[stat_inc] = (int) floor(*stats[stat_inc] * 1.1);
	stats[stat_dec] = (int) floor(*stats[stat_dec] * 0.9);
}

//! ID, Name, Getter & Setter Functions.
int Pokemon::GetId()
{
    return id;
}
std::string_view Pokemon::GetName()
{
    return name;
}
int Pokemon::GetLevel()
{
    return level;
}
int Pokemon::GetNature()
{
    return nature;
}
std::array<std::optional<int>, 6> Pokemon::GetBases()
{
    return bases;
}
std::array<std::optional<int>, 6> Pokemon::GetIvs()
{
    return ivs;
}
std::array<std::optional<int>, 6> Pokemon::GetEvs()
{
    return evs;
}
std::array<std::optional<int>, 6> Pokemon::GetStats()
{
    return stats;
}
Item Pokemon::GetItem()
{
    return item;
}
Ability Pokemon::GetAbility()
{
    return ability;
}
std::array<std::optional<Move>, 4> Pokemon::GetMoves()
{
    return moves;
}
int Pokemon::GetStatus()
{
    return status;
}

  void Pokemon::SetId(int _id)
{
    id = _id;
}
void Pokemon::SetName(std::string_view _name)
{
    name = _name;
}
void Pokemon::SetLevel(int _level)
{
    level = _level;
}
void Pokemon::SetNature(int _nature)
{
    nature = _nature;
}
void Pokemon::SetBases(std::array<std::optional<int>, 6> _bases)
{
      for (int i = 0; i < 6; i++)
      {
          bases[i] = _bases[i];
      }
  }
void Pokemon::SetIvs(std::array<std::optional<int>, 6> _ivs)
{
      for (int i = 0; i < 6; i++)
      {
          ivs[i] = _ivs[i];
      }
  }
void Pokemon::SetEvs(std::array<std::optional<int>, 6> _evs)
{
      for (int i = 0; i < 6; i++)
      {
          evs[i] = _evs[i];
      }
  }
void Pokemon::SetStats(std::array<std::optional<int>, 6> _stats)
{
      for (int i = 0; i < 6; i++)
      {
          stats[i] = _stats[i];
      }
  }
void Pokemon::SetItem(Item _item)
{
    item = _item;
}
void Pokemon::SetAbility(Ability _ability)
{
    ability = _ability;
}
void Pokemon::SetMoves(std::array<std::optional<Move>, 4> _moves)
{
      for (int i = 0; i < 6; i++)
      {
          moves[i] = _moves[i];
      }
  }
void Pokemon::SetStatus(int _status)
{
    status = _status;
}

  //! Calculate stats with Base, IV, EV, Level, and Nature.
void Pokemon::CalcStats(
    std::array<std::optional<int>, 6> _bases,
    std::array<std::optional<int>, 6> _ivs,
    std::array<std::optional<int>, 6> _evs,
    int _level, int _nature) {
		CalcHP(*_bases[0], *_ivs[0], *_evs[0], _level);
		CalcOtherStats(_bases, _ivs, _evs, _level, _nature);
}

}  // namespace PokeMaster