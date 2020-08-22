// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/MoveLoader.hpp>

#include <fstream>

namespace PokeMaster
{
void MoveLoader::Load(std::array<Move, NUM_MOVES>& moves)
{
    // Read Move data from JSON file
    std::ifstream moveFile(RESOURCES_DIR "moves.json");
    nlohmann::json j;

    moveFile >> j;

    std::size_t idx = 0;

    for (auto& data : j)
    {
        const int id = data["id"].get<int>();
        const auto name = data["identifier"].get<std::string_view>();
        const auto type = data["type_id"].get<int>();
        const auto damage_class = data["damage_class_id"].get<int>();
        const auto pp = data["pp"].get<int>();
        const auto accuracy = data["accuracy"].get<int>();
        const auto power = data["power"].get<int>();

        Move move;

        move.SetID(id);
        move.SetName(name);
        move.SetType(type);
        move.SetDamageClass(damage_class);
        move.SetPP(pp);
        move.SetAccuracy(accuracy);
        move.SetPower(power);

        moves.at(idx) = move;
        ++idx;
    }

    moveFile.close();
}
}  // namespace PokeMaster
