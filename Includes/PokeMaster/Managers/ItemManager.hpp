// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ITEM_MANAGER_HPP
#define POKEMASTER_ITEM_MANAGER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Item.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief ItemManager class.
//!
//! This class stores a list of items and provides several search methods.
//!
class ItemManager
{
 public:
    //! Returns an instance of ItemManager class.
    //! \return An instance of ItemManager class.
    static ItemManager& GetInstance();

    //! Returns a list of all items.
    //! \return A list of all items.
    static const std::array<Item, NUM_ITEMS>& GetAllItems();

 private:
    //! Constructor: Loads item data.
    ItemManager();

    static std::array<Item, NUM_ITEMS> m_items;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ITEM_MANAGER_HPP
