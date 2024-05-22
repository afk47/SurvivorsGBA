#include "enemy.h"

#include "math.h"


Enemy::Enemy()
{

    sprite.set_position(0,0);


}

void Enemy::Move(bn::fixed_point_t<12> target){

    bn::fixed_point diff = target - sprite.position();

    if (diff.x() < 1 && diff.x() > -1 && diff.y() < 1 && diff.y() > -1){
        sprite.set_position(random->get_int() % 240 - 120,random->get_int() % 120 - 60);
    }

    diff = normalizeVector(diff);

    sprite.set_position(sprite.position() + (diff / 2));
}

