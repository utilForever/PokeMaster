// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/PokemonLoader.hpp>
#include <PokeMaster/Managers/PokemonManager.hpp>

namespace PokeMaster
{
std::array<Pokemon, NUM_POKEMONS> PokemonManager::m_pokemons;

PokemonManager::PokemonManager()
{
    PokemonLoader::Load(m_pokemons);
}

PokemonManager& PokemonManager::GetInstance()
{
    static PokemonManager instance;
    return instance;
}

const std::array<Pokemon, NUM_POKEMONS>& PokemonManager::GetAllPokemons()
{
    return m_pokemons;
}
}  // namespace PokeMaster
