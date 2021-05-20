// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_UTILS_HPP
#define POKEMASTER_UTILS_HPP

#include <effolkronium/random.hpp>

#include <cmath>

using Random = effolkronium::random_static;

//! Returns a floating point number that is a rounded version of the specified
//! number. Note that GameFreak rounds down on 0.5.
//! \param num The specified number to round.
//! \return The rounded number according to GameFreak.
inline float PokeRound(float num)
{
    return (std::fmodf(num, 1.0f) > 0.5f) ? std::ceil(num) : std::floor(num);
}

//! Returns a random number between 85 and 100. Note that 85, 87, 89, 90, 92,
//! 94, 96, and 98 each have a 7.69% chance of being chosen. 86, 88, 91, 93, 95,
//! 97, and 99 each have a 5.13% chance of being chosen. 100 only has a 2.56%
//! chance of being chosen.
//! \return Returns a random number between 85 and 100.
inline int PokeRandom()
{
    const auto num = Random::get<std::size_t>(1, 10000);

    if (num >= 9744)
    {
        return 100;
    }
    else if (num >= 9231)
    {
        return 99;
    }
    else if (num >= 8462)
    {
        return 98;
    }
    else if (num >= 7949)
    {
        return 97;
    }
    else if (num >= 7180)
    {
        return 96;
    }
    else if (num >= 6667)
    {
        return 95;
    }
    else if (num >= 5898)
    {
        return 94;
    }
    else if (num >= 5385)
    {
        return 93;
    }
    else if (num >= 4616)
    {
        return 92;
    }
    else if (num >= 4103)
    {
        return 91;
    }
    else if (num >= 3334)
    {
        return 90;
    }
    else if (num >= 2565)
    {
        return 89;
    }
    else if (num >= 2052)
    {
        return 88;
    }
    else if (num >= 1283)
    {
        return 87;
    }
    else if (num >= 770)
    {
        return 86;
    }
    else
    {
        return 85;
    }
}

#endif  // POKEMASTER_UTILS_HPP
