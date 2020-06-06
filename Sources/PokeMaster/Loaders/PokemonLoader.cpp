// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/PokemonLoader.hpp>

#include <fstream>

namespace PokeMaster
{
void PokemonLoader::Load(std::array<Pokemon, NUM_POKEMONS>& pokemons)
{
    // Read Pokemon data from JSON file
    std::ifstream pokemonFile(RESOURCES_DIR "pokemon.json");
    nlohmann::json j;

    if (!pokemonFile.is_open())
    {
        throw std::runtime_error("Can't open pokemon.json");
    }

    pokemonFile >> j;

    std::size_t idx = 0;

    for (auto& data : j)
    {
        const int id = data["id"].get<int>();
        const auto name = data["identifier"].get<std::string_view>();

        Pokemon pokemon;
        pokemon.id = id;
        pokemon.name = name;

        pokemons.at(idx) = pokemon;
        ++idx;
    }

    pokemonFile.close();
}
}  // namespace PokeMaster
