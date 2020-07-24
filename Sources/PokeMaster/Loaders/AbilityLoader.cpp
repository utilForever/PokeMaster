// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/AbilityLoader.hpp>

#include <fstream>

namespace PokeMaster
{
void AbilityLoader::Load(std::array<Ability, NUM_ABILITIES>& abilities)
{
    // Read Ability data from JSON file
    std::ifstream abilityFile(RESOURCES_DIR "abilities.json");
    nlohmann::json j;

    abilityFile >> j;

    std::size_t idx = 0;

    for (auto& data : j)
    {
        const int id = data["id"].get<int>();
        const auto name = data["identifier"].get<std::string_view>();

        Ability ability;
        ability.id = id;
        ability.name = name;

        abilities.at(idx) = ability;
        ++idx;
    }

    abilityFile.close();
}
}  // namespace PokeMaster
