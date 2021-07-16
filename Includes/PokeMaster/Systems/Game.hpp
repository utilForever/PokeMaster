// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_GAME_HPP
#define POKEMASTER_GAME_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>

#include <entt/entt.hpp>

#include <optional>

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

    //! Returns a pokemon entity that matches \p name.
    //! \param name The pokemon name to find.
    //! \return A pokemon entity that matches \p name.
    [[nodiscard]] std::optional<entt::entity> FindPokemonByName(std::string_view&& name);

    //! Returns the types of the pokemon.
    //! \param entity A pokemon entity.
    //! \return The types of the pokemon.
    std::tuple<Type, Type> GetPokemonTypes(entt::entity entity);

 private:
    entt::registry m_registry;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_GAME_HPP
