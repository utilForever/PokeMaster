// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_MOVE_MANAGER_HPP
#define POKEMASTER_MOVE_MANAGER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Move.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief MoveManager class.
//!
//! This class stores a list of moves and provides several search methods.
//!
class MoveManager
{
 public:
    //! Returns an instance of MoveManager class.
    //! \return An instance of MoveManager class.
    static MoveManager& GetInstance();

    //! Returns a list of all moves.
    //! \return A list of all moves.
    static const std::array<Move, NUM_MOVES>& GetAllMoves();

 private:
    //! Constructor: Loads move data.
    MoveManager();

    static std::array<Move, NUM_MOVES> m_moves;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_MOVE_MANAGER_HPP
