#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"
#include <bn_fixed_point.h>

#include "bn_sprite_items_ball.h"

#include "bn_random.h"

class Enemy
{
public:
    Enemy();

    void Move(bn::fixed_point_t<12> target);
    Enemy SetRandom(bn::random* value) {random = value; return *this;}
private:
    bn::sprite_ptr sprite = bn::sprite_items::ball.create_sprite(0,0);
    bn::random* random;
};

#endif // ENEMY_H
