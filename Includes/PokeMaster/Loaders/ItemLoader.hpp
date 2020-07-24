// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ITEM_LOADER_HPP
#define POKEMASTER_ITEM_LOADER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Item.hpp>

#include <json/json.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief ItemLoader class.
//!
//! This class loads Item data from items.json.
//!
class ItemLoader
{
 public:
    //! Loads Item data from items.json.
    //! \param items A container to store a list of items.
    static void Load(std::array<Item, NUM_ITEMS>& items);
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ITEM_LOADER_HPP
