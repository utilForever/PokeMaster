// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_MANAGER_HPP
#define POKEMASTER_POKEMON_MANAGER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Pokemon.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief PokemonManager class.
//!
//! This class stores a list of pokemons and provides several search methods.
//!
class PokemonManager
{
 public:
    //! Returns an instance of PokemonManager class.
    //! \return An instance of PokemonManager class.
    static PokemonManager& GetInstance();

    //! Returns a list of all pokemons.
    //! \return A list of all pokemons.
    static const std::array<Pokemon, NUM_POKEMONS>& GetAllPokemons();

 private:
    //! Constructor: Loads pokemon data.
    PokemonManager();

    static std::array<Pokemon, NUM_POKEMONS> m_pokemons;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_MANAGER_HPP
