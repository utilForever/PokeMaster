// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_HPP
#define POKEMASTER_POKEMON_HPP

#include <PokeMaster/Enums/PokemonEnums.hpp>
#include <PokeMaster/Models/Ability.hpp>
#include <PokeMaster/Models/Item.hpp>
#include <PokeMaster/Models/Move.hpp>

#include <array>
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
    //! Calculate HP of Pokemon with Base, IV, EV, and Level.
    void CalcHP(int _base, int _iv, int _ev, int level);

    //! Calculate stats (except HP) of Pokemon with Base, IV, EV, Level, and
    //! Nature.
    void CalcOtherStats(std::array<int, 6> _bases, std::array<int, 6> _ivs,
                        std::array<int, 6> _evs, int level, int _nature);

 public:
    Pokemon() = default;
    Pokemon(int id, std::string_view name);

    int GetId();
    std::string_view GetName();
    int GetLevel();
    Nature GetNature();
    std::array<int, 6> GetBases();
    std::array<int, 6> GetIvs();
    std::array<int, 6> GetEvs();
    std::array<int, 6> GetStats();
    Item GetItem();
    Ability GetAbility();
    std::array<std::optional<Move>, 4> GetMoves();
    Status GetStatus();

    void SetId(int _id);
    void SetName(std::string_view _name);
    void SetLevel(int _level);
    void SetNature(Nature _nature);
    void SetBases(std::array<int, 6> _bases);
    void SetIvs(std::array<int, 6> _ivs);
    void SetEvs(std::array<int, 6> _evs);
    void SetStats(std::array<int, 6> _stats);
    void SetItem(Item _item);
    void SetAbility(Ability _ability);
    void SetMoves(std::array<std::optional<Move>, 4> _moves);
    void SetStatus(Status _status);

    //! Calculate stats with Base, IV, EV, Level, and Nature.
    void CalcStats(std::array<int, 6> _bases, std::array<int, 6> _ivs,
                   std::array<int, 6> _evs, int level, int _nature);

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
    std::array<int, 6> m_bases;
    std::array<int, 6> m_ivs;
    std::array<int, 6> m_evs;
    std::array<int, 6> m_stats;

    //! Pokemon has nature, which slightly modifies their stats.
    Nature m_nature = Nature::INVALID;
    //! Pokemon can use up to 4 moves.
    std::array<std::optional<Move>, 4> m_moves;

    Item m_item;
    Ability m_ability;

    Status m_status = Status::NORMAL;
};  // class Pokemon

}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
