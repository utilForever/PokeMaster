// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_MOVE_HPP
#define POKEMASTER_MOVE_HPP

#include <string_view>

namespace PokeMaster
{
//!
//! \brief Move class.
//!
//! A Move is a technique that a Pokémon uses during Battles. Moves are mainly
//! used to inflict damage on the opponent. Moves usually come from a natural
//! ability that the specific Pokémon has. Some moves can be used both inside
//! and outside of battle. When outside of battle, moves are usually used for
//! transportation or for removing a certain obstacle that the player runs into
//! in the game. There are three categories of moves: Physical, Special, and
//! Status. Each type holds a different kind of effect when used.
//!
class Move
{
 public:
    int id;
    std::string_view name;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_MOVE_HPP
