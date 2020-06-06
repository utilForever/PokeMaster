// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Loaders/MoveLoader.hpp>
#include <PokeMaster/Managers/MoveManager.hpp>

namespace PokeMaster
{
std::array<Move, NUM_MOVES> MoveManager::m_moves;

MoveManager::MoveManager()
{
    MoveLoader::Load(m_moves);
}

MoveManager& MoveManager::GetInstance()
{
    static MoveManager instance;
    return instance;
}

const std::array<Move, NUM_MOVES>& MoveManager::GetAllMoves()
{
    return m_moves;
}
}  // namespace PokeMaster
