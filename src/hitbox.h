#pragma once
#ifndef HITBOX_H
#define HITBOX_H

#include "math.h"


class Hitbox
{
public:
    Hitbox(Rect dim);
    bool collides(const Hitbox);
    bool is_inside(const bn::fixed_point point);
    bool is_active(){ return m_Active;}
    void set_active(bool val){m_Active = val;}
    void set_position(bn::fixed_point position){ p_Dimensions.x = position.x(); p_Dimensions.y = position.y();}
public:
    Rect p_Dimensions;

private:
    bn::fixed_point m_Center;
    bool m_Active = true;
};

#endif // HITBOX_H





