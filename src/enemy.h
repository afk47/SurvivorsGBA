#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"
#include <bn_fixed_point.h>

#include "bn_sprite_items_ball.h"

#include "bn_random.h"
#include "bn_camera_ptr.h"

class Enemy
{
public:
    Enemy(const bn::camera_ptr& camera);

    void move(bn::fixed_point_t<12> target);
    bool take_damage(int damage); //Returns true if enemy is dead

    Enemy set_random(bn::random* value) {m_random = value; return *this;}
    const bn::fixed_point position(){ return m_sprite.position(); }
    void randomize_position();

private:
    bn::camera_ptr m_camera;
    bn::sprite_ptr m_sprite;
    bn::random* m_random;
    int m_health;
};

#endif // ENEMY_H
