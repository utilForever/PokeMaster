// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_ABILITY_MANAGER_HPP
#define POKEMASTER_ABILITY_MANAGER_HPP

#include <PokeMaster/Commons/Constants.hpp>
#include <PokeMaster/Models/Ability.hpp>

#include <array>

namespace PokeMaster
{
//!
//! \brief AbilityManager class.
//!
//! This class stores a list of abilities and provides several search methods.
//!
class AbilityManager
{
 public:
    //! Returns an instance of AbilityManager class.
    //! \return An instance of AbilityManager class.
    static AbilityManager& GetInstance();

    //! Returns a list of all abilities.
    //! \return A list of all abilities.
    static const std::array<Ability, NUM_ABILITIES>& GetAllAbilities();

 private:
    //! Constructor: Loads ability data.
    AbilityManager();

    static std::array<Ability, NUM_ABILITIES> m_abilities;
};
}  // namespace PokeMaster

#endif  // POKEMASTER_ABILITY_MANAGER_HPP
