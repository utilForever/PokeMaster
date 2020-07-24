// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ABILITY_HPP
#define POKEMASTER_ABILITY_HPP

#include <string_view>

namespace PokeMaster
{
//!
//! \brief Ability class.
//!
//! Pokemon Abilities are various powers or characteristics that each Pokémon
//! possesses and uses passively in a Pokémon battle. Abilities were introduced
//! in Generation III as an all new game mechanic. Each and every Pokémon has an
//! ability, and can only have one at a time. Some abilities are exclusive to
//! certain Pokémon and Evolution lines, while others are known by many Pokémon.
//!
class Ability
{
 public:
    int id;
    std::string_view name;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ABILITY_HPP
