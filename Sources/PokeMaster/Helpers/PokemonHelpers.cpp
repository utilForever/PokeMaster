// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Components/Name.hpp>
#include <PokeMaster/Helpers/PokemonHelpers.hpp>

#include <json/json.hpp>

#include <fstream>

namespace PokeMaster::Pokemon
{
void LoadData(entt::registry& registry)
{
    // Read Item data from JSON file
    std::ifstream moveFile(RESOURCES_DIR "pokemon.json");
    nlohmann::json j;

    moveFile >> j;

    for (auto& data : j)
    {
        auto entity = registry.create();
        registry.emplace<Name>(entity, data["identifier"].get<std::string>());
    }

    moveFile.close();
}
}  // namespace PokeMaster::Pokemon