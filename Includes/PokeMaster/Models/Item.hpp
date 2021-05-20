// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ITEM_HPP
#define POKEMASTER_ITEM_HPP

#include <string_view>

namespace PokeMaster
{
//!
//! \brief Item class.
//!
//! An item (Japanese: 道具 tool) is an object in the Pokémon games which the
//! player can pick up, keep in their Bag, and use in some manner. They have
//! various uses, including healing, powering up, helping one to catch Pokémon,
//! or accessing new areas.
//!
class Item
{
 public:
    int id;
    std::string_view name;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ITEM_HPP
