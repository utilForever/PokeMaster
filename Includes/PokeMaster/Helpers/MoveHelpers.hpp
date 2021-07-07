// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_MOVE_HELPERS_HPP
#define POKEMASTER_MOVE_HELPERS_HPP

#include <entt/entt.hpp>

namespace PokeMaster::Move
{
//! Loads move data from moves.json.
//!
//! A Move is a technique that a Pokémon uses during Battles. Moves are mainly
//! used to inflict damage on the opponent. Moves usually come from a natural
//! ability that the specific Pokémon has. Some moves can be used both inside
//! and outside of battle. When outside of battle, moves are usually used for
//! transportation or for removing a certain obstacle that the player runs into
//! in the game. There are three categories of moves: Physical, Special, and
//! Status. Each type holds a different kind of effect when used.
//!
//! \param registry A registry of the entity-component system.
void LoadData(entt::registry& registry);
}  // namespace PokeMaster::Move

#endif  // POKEMASTER_MOVE_HELPERS_HPP
