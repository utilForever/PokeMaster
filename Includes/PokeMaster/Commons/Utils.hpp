// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_UTILS_HPP
#define POKEMASTER_UTILS_HPP

#include <cmath>

//! Returns a floating point number that is a rounded version of the specified
//! number. Note that GameFreak rounds down on 0.5.
//! \param num The specified number to round.
//! \return The rounded number according to GameFreak.
inline float PokeRound(float num)
{
    return (std::fmodf(num, 1.0f) > 0.5f) ? std::ceil(num) : std::floor(num);
}

#endif  // POKEMASTER_UTILS_HPP
