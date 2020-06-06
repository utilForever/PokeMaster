// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_HPP
#define POKEMASTER_POKEMON_HPP

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
    int id;
    std::string_view name;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
