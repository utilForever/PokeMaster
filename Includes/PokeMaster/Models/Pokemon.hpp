// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_HPP
#define POKEMASTER_POKEMON_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>
#include <PokeMaster/Models/Item.hpp>
#include <PokeMaster/Models/Move.hpp>
#include <PokeMaster/Models/Stats.hpp>

#include <optional>
#include <string_view>

namespace PokeMaster
{
//!
//! \brief Pokemon class.
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
class Pokemon
{
 public:
    //! Default constructor.
    Pokemon() = default;

    //! Constructs Pokémon with given \p id and \p name.
    //! \param id The unique ID of Pokémon.
    //! \param name The name of Pokémon.
    Pokemon(int id, std::string_view name);

    //! Constructs Pokémon with various arguments.
    //! \param id The unique ID of Pokémon.
    //! \param name The name of Pokémon.
    //! \param level The level of Pokémon.
    //! \param bases The base stats of Pokémon.
    //! \param ivs The IV stats of Pokémon.
    //! \param evs The EV stats of Pokémon.
    //! \param nature The nature of Pokémon.
    Pokemon(int id, std::string_view name, int level, Stats bases, Stats ivs, Stats evs,
            Nature nature);

    //! Returns the unique ID of Pokémon.
    //! \return The unique ID of Pokémon.
    [[nodiscard]] int GetID() const;

    //! Returns the name of Pokémon.
    //! \return The name of Pokémon.
    [[nodiscard]] std::string_view GetName() const;

    //! Returns the type 1 of Pokémon.
    //! \return The type 1 of Pokémon.
    [[nodiscard]] Type GetType1() const;

    //! Returns the type 2 of Pokémon.
    //! \return The type 2 of Pokémon.
    [[nodiscard]] Type GetType2() const;

    //! Returns the level of Pokémon.
    //! \return The level of Pokémon.
    [[nodiscard]] int GetLevel() const;

    //! Returns a list of stats of Pokémon.
    //! \return A list of stats of Pokémon.
    [[nodiscard]] Stats GetStats() const;

    //! Returns the nature of Pokémon.
    //! \return The nature of Pokémon.
    [[nodiscard]] Nature GetNature() const;

    //! Returns the ability of Pokémon.
    //! \return The ability of Pokémon.
    [[nodiscard]] Ability GetAbility() const;

    //! Returns the item of Pokémon.
    //! \return The item of Pokémon.
    [[nodiscard]] std::optional<Item> GetItem() const;

    //! Returns the status of Pokémon.
    //! \return The status of Pokémon.
    [[nodiscard]] Status GetStatus() const;

    //! Returns a list of moves of Pokémon.
    //! \return A list of moves of Pokémon.
    [[nodiscard]] std::array<std::optional<Move>, 4> GetMoves() const;

    //! Calculates stats of Pokémon with base, IV, EV, level and nature.
    void CalcStats();

    //! Calculates HP of Pokémon with base, IV, EV and level.
    void CalcHP();

    //! Calculate stats except HP of Pokémon with base, IV, EV, level and
    //! nature.
    void CalcOtherStats();

 private:
    int m_id = -1;
    std::string_view m_name;

    Type m_type1 = Type::INVALID;
    Type m_type2 = Type::INVALID;
    int m_level = 1;

    //! 6 stats are 'HP', 'ATTACK', 'DEFENSE', 'SPECIAL_ATTACK',
    //! 'SPECIAL_DEFENSE', and 'SPEED'. These values are calculated from various
    //! factors; Base, IV, EV and Nature. They can be accessed with stats[HP],
    //! stats[ATTACK], and so on.
    Stats m_bases;
    Stats m_ivs;
    Stats m_evs;
    Stats m_stats;

    Nature m_nature = Nature::INVALID;
    Ability m_ability = Ability::INVALID;
    std::optional<Item> m_item;
    Status m_status = Status::HEALTHY;

    std::array<std::optional<Move>, 4> m_moves;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
