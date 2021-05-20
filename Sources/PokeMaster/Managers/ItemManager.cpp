// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/ItemLoader.hpp>
#include <PokeMaster/Managers/ItemManager.hpp>

namespace PokeMaster
{
std::array<Item, NUM_ITEMS> ItemManager::m_items;

ItemManager::ItemManager()
{
    ItemLoader::Load(m_items);
}

ItemManager& ItemManager::GetInstance()
{
    static ItemManager instance;
    return instance;
}

const std::array<Item, NUM_ITEMS>& ItemManager::GetAllItems()
{
    return m_items;
}
}  // namespace PokeMaster
