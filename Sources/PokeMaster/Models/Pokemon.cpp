// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Models/Pokemon.hpp>

#include <cmath>

namespace PokeMaster
{

//! Pokemon stats.
enum STAT
{
	HP,
	ATTACK,
	DEFENSE,
	SPECIAL_ATTACK,
	SPECIAL_DEFENSE,
	SPEED
};

//! Pokemon natures.
//! First Digit of Nature Code indicates a stat which will be increased by 10%.
//! Second Digit of Nature Code indicates a stat which will be decreased by 10%.
//! Numbers 1~5 correspond to ATTACK, DEFENSE, SPECIAL_ATTACK, SPECIAL_DEFENSE and SPEED.
enum NATURE
{
	NATURE_ADAMANT    = 13,        //!      +ATTACK            -SPECIAL_ATTACK
	NATURE_BASHFUL    = 0 , 
	NATURE_BOLD       = 21,        //!      +DEFENSE           -ATTACK
	NATURE_BRAVE      = 15,        //!      +ATTACK            -SPEED
	NATURE_CALM       = 41,        //!      +SPECIAL_DEFENSE   -ATTACK
	NATURE_CAREFUL    = 43,        //!      +SPECIAL_DEFENSE   -SPECIAL_ATTACK
	NATURE_DOCILE     = 0 ,
	NATURE_GENTLE     = 42,        //!      +SPECIAL_DEFENSE   -DEFENSE
	NATURE_HARDY      = 0 ,
	NATURE_HASTY      = 52,        //!      +SPEED             -DEFENSE
	NATURE_IMPISH     = 23,        //!      +DEFENSE           -SPECIAL_ATTACK
	NATURE_JOLLY      = 53,        //!      +SPEED             -SPECIAL_ATTACK
	NATURE_LAX        = 24,        //!      +DEFENSE           -SPECIAL_DEFENSE
	NATURE_LONELY     = 12,        //!      +ATTACK            -DEFENSE
	NATURE_MILD       = 32,        //!      +SPECIAL_ATTACK    -DEFENSE
	NATURE_MODEST     = 31,        //!      +SPECIAL_ATTACK    -ATTACK
	NATURE_NAIVE      = 54,        //!      +SPEED             -SPECIAL_DEFENSE
	NATURE_NAUGHTY    = 14,        //!      +ATTACK            -SPECIAL_DEFENSE
	NATURE_QUIET      = 35,        //!      +SPECIAL_ATTACK    -SPEED
	NATURE_QUIRKY     = 0 ,
	NATURE_RASH       = 34,        //!      +SPECIAL_ATTACK    -SPECIAL_DEFENSE
	NATURE_RELAXED    = 25,        //!      +DEFENSE           -SPEED
	NATURE_SASSY      = 45,        //!      +SPECIAL_DEFENSE   -SPEED
	NATURE_SERIOUS    = 0 ,
	NATURE_TIMID      = 52         //!      +SPEED             -ATTACK
};

//! Pokemon status.
enum STATUS
{
	STATUS_HEALTHY,
	STATUS_POISONED,
	STATUS_BADPOISONED,
	STATUS_BURNED,
	STATUS_PARALYZED,
	STATUS_ASLEEP,
	STATUS_FROZEN
};

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