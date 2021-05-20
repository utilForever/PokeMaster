// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_LOADER_HPP
#define POKEMASTER_POKEMON_LOADER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Pokemon.hpp>

#include <json/json.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief PokemonLoader class.
//!
//! This class loads Pokemon data from pokemon.json.
//!
class PokemonLoader
{
 public:
    //! Loads Pokemon data from pokemon.json.
    //! \param pokemons A container to store a list of pokemons.
    static void Load(std::array<Pokemon, NUM_POKEMONS>& pokemons);
};
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_LOADER_HPP
