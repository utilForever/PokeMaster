// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_GAME_HPP
#define POKEMASTER_GAME_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Components/Stats.hpp>
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

    //! Adds a pokemon for the player.
    //! \param name The name of the pokemon.
    //! \param level The level of the pokemon.
    //! \param individualValues A list of individual values.
    //! \param effortValues A list of effort values.
    //! \param nature The nature of pokemon.
    //! \return An added pokemon entity.
    entt::entity AddPokemon(std::string_view name, int level,
                            StatStorage individualValues, StatStorage effortValues,
                            Nature nature);

    //! Returns a pokemon entity that matches \p index.
    //! \param index The pokemon index to find.
    //! \return A pokemon entity that matches \p index.
    [[nodiscard]] std::optional<entt::entity> FindPokemonByIndex(int index);

    //! Returns a pokemon entity that matches \p name.
    //! \param name The pokemon name to find.
    //! \return A pokemon entity that matches \p name.
    [[nodiscard]] std::optional<entt::entity> FindPokemonByName(std::string_view&& name);

    //! Returns the level of the pokemon.
    //! \param entity A pokemon entity.
    //! \return The level of the pokemon.
    int GetPokemonLevel(entt::entity entity);

    //! Returns the types of the pokemon.
    //! \param entity A pokemon entity.
    //! \return The types of the pokemon.
    std::tuple<Type, Type> GetPokemonTypes(entt::entity entity);

    //! Returns the stats of the pokemon.
    //! \param entity A pokemon entity.
    //! \return The stats of the pokemon.
    StatStorage GetPokemonStats(entt::entity entity);

 private:
    entt::registry m_registry;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_GAME_HPP
