// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Managers/ItemManager.hpp>

using namespace PokeMaster;

TEST_CASE("[ItemManager] - GetAllItems")
{
    auto items = ItemManager::GetInstance().GetAllItems();
    for (auto& item : items)
    {
        CHECK_NE(item.id, 0);
        CHECK_FALSE(item.name.empty());
    }
}