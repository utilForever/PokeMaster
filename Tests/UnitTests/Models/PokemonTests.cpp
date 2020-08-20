// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <PokeMaster/Models/Pokemon.hpp>

using namespace PokeMaster;

TEST_CASE("[Pokemon] - Stats")
{
    const Pokemon pokemon1{ 1,
                            "Abomasnow",
                            50,
                            { 90, 92, 75, 92, 85, 60 },
                            { 31, 31, 31, 31, 31, 31 },
                            { 252, 4, 0, 252, 0, 0 },
                            Nature::QUIET };

    Stats stats = pokemon1.GetStats();
    CHECK_EQ(stats[Stat::HP], 197);
    CHECK_EQ(stats[Stat::ATTACK], 113);
    CHECK_EQ(stats[Stat::DEFENSE], 95);
    CHECK_EQ(stats[Stat::SPECIAL_ATTACK], 158);
    CHECK_EQ(stats[Stat::SPECIAL_DEFENSE], 105);
    CHECK_EQ(stats[Stat::SPEED], 72);
}