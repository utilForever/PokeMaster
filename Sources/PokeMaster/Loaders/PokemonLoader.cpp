// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

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

    pokemonFile >> j;

    std::size_t idx = 0;

    for (auto& data : j)
    {
        const int id = data["id"].get<int>();
        const auto name = data["identifier"].get<std::string_view>();

        const Pokemon pokemon{id, name};
        pokemons.at(idx) = pokemon;
        ++idx;
    }

    pokemonFile.close();
}
}  // namespace PokeMaster
