// Copyright (c) 2021 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_TAGS_HPP
#define POKEMASTER_TAGS_HPP

#include <entt/entt.hpp>

namespace PokeMaster
{
namespace Tag
{
using namespace entt::literals;

using Pokemon = entt::tag<"pokemon"_hs>;
using PlayerPokemon = entt::tag<"player_pokemon"_hs>;
using Item = entt::tag<"item"_hs>;
using Move = entt::tag<"move"_hs>;
}  // namespace Tag
}  // namespace PokeMaster

#endif  // POKEMASTER_INDEX_HPP
