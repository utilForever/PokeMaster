// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_HELPERS_HPP
#define POKEMASTER_POKEMON_HELPERS_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Components/Stats.hpp>
#include <PokeMaster/Enums/PokemonEnums.hpp>

#include <entt/entt.hpp>

#include <optional>
#include <tuple>

namespace PokeMaster::Pokemon
{
//! Loads Pokémon data from pokemon.json.
//!
//! A Pokémon (Japanese: ポケモン Pokemon), shortened from Pocket Monster
//! (Japanese: ポケットモンスター Poketto Monsutaa), is any of the 890
//! documented species of the eponymous collectible organisms that have evolved
//! and inhabited the fictional Pokémon World with an innate connection to
//! element-based supernatural powers. In that world, Pokémon are commonly
//! captured and trained by humans, primarily for companionship and/or to be
//! used in popular fighting competitions. Nearly all Pokémon are able to
//! manipulate energy or matter through paranormal means, with the specifics of
//! these abilities determined for each Pokémon largely by their elemental
//! "type".
//!
//! \param registry A registry of the entity-component system.
void LoadData(entt::registry& registry);

//! Adds a Pokémon for the player.
//! \param registry A registry of the entity-component system.
//! \param name The name of the Pokémon.
//! \param level The level of the Pokémon.
//! \param individualValues A list of individual values.
//! \param effortValues A list of effort values.
//! \param nature The nature of Pokémon.
//! \return An added Pokémon entity.
entt::entity Add(entt::registry& registry, std::string_view&& name, int level,
                 StatStorage individualValues, StatStorage effortValues, Nature nature);

//! Calculates stats of Pokémon with base, IV, EV, level and nature.
//! \param registry A registry of the entity-component system.
//! \param entity A Pokémon entity.
void CalculateStats(entt::registry& registry, entt::entity entity);

//! Returns a Pokémon entity that matches \p index.
//! \param registry A registry of the entity-component system.
//! \param index The Pokémon index to find.
//! \return A Pokémon entity that matches \p index.
[[nodiscard]] std::optional<entt::entity> FindByIndex(entt::registry& registry,
                                                      int index);

//! Returns a Pokémon entity that matches \p name.
//! \param registry A registry of the entity-component system.
//! \param name The Pokémon name to find.
//! \return A Pokémon entity that matches \p name.
[[nodiscard]] std::optional<entt::entity> FindByName(entt::registry& registry,
                                                     std::string_view&& name);

//! Returns the level of the Pokémon.
//! \param registry A registry of the entity-component system.
//! \param entity A Pokémon entity.
//! \return The level of the Pokémon.
int GetLevel(entt::registry& registry, entt::entity entity);

//! Returns the types of the Pokémon.
//! \param registry A registry of the entity-component system.
//! \param entity A Pokémon entity.
//! \return The types of the Pokémon.
std::tuple<Type, Type> GetTypes(entt::registry& registry, entt::entity entity);

//! Returns the stats of the Pokémon.
//! \param registry A registry of the entity-component system.
//! \param entity A Pokémon entity.
//! \return The stats of the Pokémon.
StatStorage GetStats(entt::registry& registry, entt::entity entity);
}  // namespace PokeMaster::Pokemon

#endif  // POKEMASTER_POKEMON_HELPERS_HPP
