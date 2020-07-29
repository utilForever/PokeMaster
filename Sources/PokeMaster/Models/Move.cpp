// Copyright (c) 2020 PokeMaster Team
// Chris Ohk, Seungwoo Yoo, Seungwoo Lee, Eunsaem Ko

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <PokeMaster/Models/Move.hpp>

namespace PokeMaster
{
    const int Move::GetID()
    {
        return id;
    }

    const std::string_view Move::GetName()
    {
        return name;
    }

    const int Move::GetType()
    {
        return type;
    }

    const int Move::GetDamageClass()
    {
        return damage_class;
    }

    const int Move::GetPP()
    {
        return pp;
    }

    const int Move::GetAccuracy()
    {
        return accuracy;
    }

    const int Move::GetPower()
    {
        return power;
    }

    void Move::SetID(int in_id)
    {
        this->id = in_id;
    }

    void Move::SetName(std::string_view in_name)
    {
        this->name = in_name;
    }

    void Move::SetType(int in_type_id)
    {
        this->type = in_type_id;
    }

    void Move::SetDamageClass(int in_damage_class_id)
    {
        this->damage_class = in_damage_class_id;
    }

    void Move::SetPP(int in_pp)
    {
        this->pp = in_pp;
    }

    void Move::SetAccuracy(int in_accuracy)
    {
        this->accuracy = in_accuracy;
    }

    void Move::SetPower(int in_power)
    {
        this->power = in_power;
    }

}  // namespace PokeMaster
