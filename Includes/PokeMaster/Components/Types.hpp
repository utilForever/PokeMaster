// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_TYPES_HPP
#define POKEMASTER_TYPES_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>

namespace PokeMaster
{
//!
//! \brief Types struct.
//!
//! This struct stores the types of the entity. Types refer to different elemental
//! properties associated with both Pokémon and their moves.
//!
//! Pokémon themselves can have up to two types, making them dual-type Pokémon,
//! but moves can only be one type (with the exception of the move Flying Press
//! which is a Fighting/Flying-type move).
//!
struct Types
{
    Type type1;
    Type type2;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_TYPES_HPP
