// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ABILITY_LOADER_HPP
#define POKEMASTER_ABILITY_LOADER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Ability.hpp>

#include <json/json.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief AbilityLoader class.
//!
//! This class loads Ability data from abilities.json.
//!
class AbilityLoader
{
 public:
    //! Loads Ability data from abilities.json.
    //! \param abilities A container to store a list of abilities.
    static void Load(std::array<Ability, NUM_ABILITIES>& abilities);
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ABILITY_LOADER_HPP
