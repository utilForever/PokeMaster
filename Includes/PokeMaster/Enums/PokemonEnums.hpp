// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Won Park

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_POKEMON_ENUMS_HPP
#define POKEMASTER_POKEMON_ENUMS_HPP

#include <string_view>

namespace PokeMaster
{
//! \brief An enumerator for identifying the type of Pokémon.
enum class Type
{
    INVALID,
    NORMAL,
    FIGHTING,
    FLYING,
    POISON,
    GROUND,
    ROCK,
    BUG,
    GHOST,
    STEEL,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    PSYCHIC,
    ICE,
    DRAGON,
    DARK,
    FAIRY
};

//! \brief An enumerator for identifying the stat of Pokémon.
enum class Stat
{
    INVALID,
    HP,
    ATTACK,
    DEFENSE,
    SPECIAL_ATTACK,
    SPECIAL_DEFENSE,
    SPEED,
    ACCURACY,
    EVASION
};

//! \brief An enumerator for identifying the nature of Pokémon.
//! First digit of nature code indicates a stat which will be increased by 10%.
//! Second digit of nature code indicates a stat which will be decreased by 10%.
//! Numbers 1~5 correspond to ATTACK, DEFENSE, SPECIAL_ATTACK, SPECIAL_DEFENSE
//! and SPEED.
enum class Nature
{
    INVALID,
    HARDY,
    BOLD,
    MODEST,
    CALM,
    TIMID,
    LONELY,
    DOCILE,
    MILD,
    GENTLE,
    HASTY,
    ADAMANT,
    IMPISH,
    BASHFUL,
    CAREFUL,
    RASH,
    JOLLY,
    NAUGHTY,
    LAX,
    QUIRKY,
    NAIVE,
    BRAVE,
    RELAXED,
    QUIET,
    SASSY,
    SERIOUS
};

//! \brief An enumerator for identifying the ability of Pokémon.
enum class Ability
{
#define X(a) a,
#include "PokeMaster/Enums/Ability.def"
#undef X
};

const std::string_view ABILITY_STR[] = {
#define X(a) #a,
#include "PokeMaster/Enums/Ability.def"
#undef X
};

//! \brief An enumerator for identifying the status of Pokémon.
enum class Status
{
    NORMAL,
    HEALTHY,
    POISONED,
    BADLY_POISONED,
    BURNED,
    PARALYZED,
    ASLEEP,
    FROZEN
};

template <class T>
T StrToEnum(const std::string_view&);
template <class T>
std::string_view EnumToStr(T);

#define STR2ENUM(TYPE, ARRAY)                                                \
    template <>                                                              \
    inline TYPE StrToEnum<TYPE>(const std::string_view& str)                 \
    {                                                                        \
        for (std::size_t i = 0; i < (sizeof(ARRAY) / sizeof(ARRAY[0])); ++i) \
        {                                                                    \
            if (ARRAY[i] == str)                                             \
            {                                                                \
                return TYPE(i);                                              \
            }                                                                \
        }                                                                    \
                                                                             \
        return TYPE(0);                                                      \
    }

#define ENUM2STR(TYPE, ARRAY)                       \
    template <>                                     \
    inline std::string_view EnumToStr<TYPE>(TYPE v) \
    {                                               \
        return ARRAY[static_cast<int>(v)];          \
    }

#define ENUM_AND_STR(TYPE, ARRAY) \
    STR2ENUM(TYPE, ARRAY)         \
    ENUM2STR(TYPE, ARRAY)

ENUM_AND_STR(Ability, ABILITY_STR)
}  // namespace PokeMaster

#endif  // POKEMASTER_POKEMON_HPP
