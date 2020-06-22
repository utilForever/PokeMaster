// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Managers/AbilityManager.hpp>

using namespace PokeMaster;

TEST_CASE("[AbilityManager] - GetAllAbilities")
{
    auto abilities = AbilityManager::GetInstance().GetAllAbilities();
    for (auto& ability : abilities)
    {
        CHECK_NE(ability.id, 0);
        CHECK_FALSE(ability.name.empty());
    }
}