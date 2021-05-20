// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_MOVE_LOADER_HPP
#define POKEMASTER_MOVE_LOADER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Move.hpp>

#include <json/json.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief MoveLoader class.
//!
//! This class loads Move data from moves.json.
//!
class MoveLoader
{
 public:
    //! Loads Move data from moves.json.
    //! \param moves A container to store a list of moves.
    static void Load(std::array<Move, NUM_MOVES>& moves);
};
}  // namespace PokeMaster

#endif  // POKEMASTER_MOVE_LOADER_HPP
