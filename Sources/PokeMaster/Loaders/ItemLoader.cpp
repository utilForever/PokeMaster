// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/ItemLoader.hpp>

#include <fstream>

namespace PokeMaster
{
void ItemLoader::Load(std::array<Item, NUM_ITEMS>& items)
{
    // Read Item data from JSON file
    std::ifstream itemFile(RESOURCES_DIR "items.json");
    nlohmann::json j;

    itemFile >> j;

    std::size_t idx = 0;

    for (auto& data : j)
    {
        const int id = data["id"].get<int>();
        const auto name = data["identifier"].get<std::string_view>();

        Item item;
        item.id = id;
        item.name = name;

        items.at(idx) = item;
        ++idx;
    }

    itemFile.close();
}
}  // namespace PokeMaster
