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

    Enemy set_random(bn::random* value) {random = value; return *this;}
    const bn::fixed_point position(){ return sprite.position(); }
    void randomize_position();

private:
    bn::sprite_ptr sprite = bn::sprite_items::ball.create_sprite(0,0);
    bn::random* random;
    int health;
};

#endif // ENEMY_H
