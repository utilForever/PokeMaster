// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef POKEMASTER_MOVE_HPP
#define POKEMASTER_MOVE_HPP

#include <string_view>

namespace PokeMaster
{
//!
//! \brief Move class.
//!
//! A Move is a technique that a Pokémon uses during Battles. Moves are mainly
//! used to inflict damage on the opponent. Moves usually come from a natural
//! ability that the specific Pokémon has. Some moves can be used both inside
//! and outside of battle. When outside of battle, moves are usually used for
//! transportation or for removing a certain obstacle that the player runs into
//! in the game. There are three categories of moves: Physical, Special, and
//! Status. Each type holds a different kind of effect when used.
//!

class Move
{
 public:

    /*
     * Getters for accessing member variables of Move class
     */

    //! Returns the ID of a move
    //! \return The ID of a move
    const int GetID();

    //! Returns the name(identifier) of a move
    //! \return The name(identifier) of a move
    const std::string_view GetName();

    //! Returns the type of a move
    //! \return The type of a move
    const int GetType();

    //! Returns the damage class of a move
    //! \return The damage class of a move
    const int GetDamageClass();

    //! Returns the PP(Power Point) of a move
    //! \return The PP(Power Point) of a move
    const int GetPP();

    //! Returns the accuracy of a move
    //! \return The accuracy of a move
    const int GetAccuracy();

    //! Returns the power of a move
    //! \return The power of a move
    const int GetPower();

    /*
     * Setters for modifying member variables of Move class
     */

    //! Set the ID of a move as 'in_id'
    //! \return Nothing
    void SetID(int in_id);

    //! Set the name of a move as 'in_name'
    //! \return Nothing
    void SetName(std::string_view in_name);

    //! Set the type of a move as 'in_type_id'
    //! \return Nothing
    void SetType(int in_type_id);

    //! Set the damage class of a move as 'in_damage_class_id'
    //! \return Nothing
    void SetDamageClass(int in_damage_class_id);

    //! Set the PP(Power Point) of a move as 'in_pp'
    //! \return Nothing
    void SetPP(int in_pp);

    //! Set the accuracy of a move as 'in_accuracy'
    //! \return Nothing
    void SetAccuracy(int in_accuracy);

    //! Set the power of a move as 'in_power'
    //! \return Nothing
    void SetPower(int in_power);

private:
    int id;
    std::string_view name;
    int type;
    int damage_class;
    int pp;
    int accuracy;
    int power;

};
}  // namespace PokeMaster

#endif  // POKEMASTER_MOVE_HPP
