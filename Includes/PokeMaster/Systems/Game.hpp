﻿// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_GAME_HPP
#define POKEMASTER_GAME_HPP

#include <entt/entt.hpp>

namespace PokeMaster
{
//!
//! \brief Game class.
//!
//! This class stores Pokémon battle game states which consists of
//! information of both players.
//!
class Game
{
 public:
    //! Constructs new game and loads related data.
    Game();

 private:
    entt::registry m_registry;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_GAME_HPP
