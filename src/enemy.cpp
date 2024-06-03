#include "enemy.h"

#include "math.h"


Enemy::Enemy(const bn::camera_ptr& camera)
    :  health(10)
{

    sprite.set_position(0,0);
    sprite.set_camera(camera);

}

void Enemy::Move(bn::fixed_point_t<12> target){

    bn::fixed_point diff = target - sprite.position();

    diff = normalizeVector(diff);

    sprite.set_position(sprite.position() + (diff / 2));
}


bool Enemy::takeDamage(int damage){
    health -= damage;
    if(health <= 0){
        return true;
    }

    return false;

}

void Enemy::RandomizePosition(){
    sprite.set_position(random->get_int() % 512 - 256, random->get_int() % 512 - 256);
}
