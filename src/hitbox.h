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
    bool is_active(){ return m_active;}
    void set_active(bool val){m_active = val;}
    void set_position(bn::fixed_point position){ p_dimensions.x = position.x(); p_dimensions.y = position.y();}
public:
    Rect p_dimensions;

private:
    bn::fixed_point m_center;
    bool m_active = true;
};

#endif // HITBOX_H





