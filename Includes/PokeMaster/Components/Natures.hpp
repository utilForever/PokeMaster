// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_NATURES_HPP
#define POKEMASTER_NATURES_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>

namespace PokeMaster
{
//!
//! \brief Natures struct.
//!
//! Natures (せいかく Personality ) are a Pokémon's personality and effect their Stats as
//! it levels up. Specifically, all but five Natures can affect two stats, increasing one
//! by 10% and decreasing another by 10%. Additionally, all but the same five stats affect
//! what kind of flavor the Pokémon will like as well. Natures have the potential to
//! affect any Stat except for HP. In total, there are 24 different types of natures that
//! any Pokémon is capable of having.
//!
struct Natures
{
    Nature nature;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_NATURES_HPP
