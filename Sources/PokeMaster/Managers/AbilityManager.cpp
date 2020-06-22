// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/AbilityLoader.hpp>
#include <PokeMaster/Managers/AbilityManager.hpp>

namespace PokeMaster
{
std::array<Ability, NUM_ABILITIES> AbilityManager::m_abilities;

AbilityManager::AbilityManager()
{
    AbilityLoader::Load(m_abilities);
}

AbilityManager& AbilityManager::GetInstance()
{
    static AbilityManager instance;
    return instance;
}

const std::array<Ability, NUM_ABILITIES>& AbilityManager::GetAllAbilities()
{
    return m_abilities;
}
}  // namespace PokeMaster
