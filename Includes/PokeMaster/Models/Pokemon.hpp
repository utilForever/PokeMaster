// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_HPP
#define POKEMASTER_POKEMON_HPP

#include <PokeMaster/Includes/PokeMaster/Commons.hpp>

#include <iostream>
#include <cmath>

#include <string_view>
#include <array>

namespace PokeMaster
{
//!
//! \brief Pokemon class.
//!
//! A Pokémon (Japanese: ポケモン Pokemon), shortened from Pocket Monster
//! (Japanese: ポケットモンスター Poketto Monsutaa), is any of the 890
//! documented species of the eponymous collectible organisms that have evolved
//! and inhabited the fictional Pokémon World with an innate connection to
//! element-based supernatural powers. In that world, Pokémon are commonly
//! captured and trained by humans, primarily for companionship and/or to be
//! used in popular fighting competitions. Nearly all Pokémon are able to
//! manipulate energy or matter through paranormal means, with the specifics of
//! these abilities determined for each Pokémon largely by their elemental
//! "type".
//!
class Pokemon
{
const int id;
const std::string_view name;
const int type1, type2;
int level;

//! Pokemon has nature, which slightly modifies their stats.
const int nature;

//! 6 stats are 'HP', 'ATTACK', 'DEFENSE', 'SPECIAL_ATTACK', 'SPECIAL_DEFENSE', and 'SPEED'.
//! These values are calculated from various factors; Base, IV, EV and Nature.
//! They can be accessed with stats[HP], stats[ATTACK], and so on.
std::array<std::optional<int>, 6> bases;
std::array<std::optional<int>, 6> ivs;
std::array<std::optional<int>, 6> evs;
std::array<std::optional<int>, 6> stats;

Item item;
Ability ability;

//! Pokemon can use up to 4 moves.
std::array<std::optional<Move>, 4> moves;

int status;

//! Calculate HP of Pokemon with Base, IV, EV, and Level.
void CalcHP(int _base, int _iv, int _ev, int level);

//! Calculate stats (except HP) of Pokemon with Base, IV, EV, Level, and Nature.
void CalcOtherStats(
  std::array<std::optional<int>, 6> _bases,
  std::array<std::optional<int>, 6> _ivs,
  std::array<std::optional<int>, 6> _evs,
  int level, int _nature);

//! Getter & Setter Functions.
public:
  int GetId();
  std::string_view GetName();
  int GetLevel();
  int GetNature();
  std::array<std::optional<int>, 6> GetBases();
  std::array<std::optional<int>, 6> GetIvs();
  std::array<std::optional<int>, 6> GetEvs();
  std::array<std::optional<int>, 6> GetStats();
  Item GetItem();
  Ability GetAbility();
  std::array<std::optional<Move>, 4> Getmoves();
  int GetStatus();

  void SetId(int _id);
  void SetName(std::string_view _name);
  void SetLevel(int _level);
  void SetNature(int _nature);
  void SetStats(std::array<std::optional<int>, 6> _bases);
  void SetStats(std::array<std::optional<int>, 6> _ivs);
  void SetStats(std::array<std::optional<int>, 6> _evs);
  void SetStats(std::array<std::optional<int>, 6> _stats);
  void SetItem(Item _item);
  void SetAbility(Ability _ability);
  void SetMoves(std::array<std::optional<Move>, 4> _moves);
  void SetStatus(int _status);

  //! Calculate stats with Base, IV, EV, Level, and Nature.
  void CalcStats(
    std::array<std::optional<int>, 6> _bases,
    std::array<std::optional<int>, 6> _ivs,
    std::array<std::optional<int>, 6> _evs,
    int level, int _nature);
  

};

}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
