// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Managers/MoveManager.hpp>

using namespace PokeMaster;

TEST_CASE("[MoveManager] - GetAllMoves")
{
    auto moves = MoveManager::GetInstance().GetAllMoves();
    for (auto& move : moves)
    {
        CHECK_NE(move.GetID(), 0);
        CHECK_FALSE(move.GetName().empty());
        CHECK_NE(move.GetType(), 0);
        CHECK_NE(move.GetDamageClass(), 0);
        CHECK_NE(move.GetPP(), 0);
        CHECK_NE(move.GetAccuracy(), 0);
    }
}