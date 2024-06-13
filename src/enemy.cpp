
#include "enemy.h"

#include "math.h"


Enemy::Enemy(const bn::camera_ptr& camera)
    :  m_sprite(bn::sprite_items::ball.create_sprite(0,0)),
    m_health(10),
    m_camera(camera)
{

    m_sprite.set_position(0,0);
    m_sprite.set_camera(m_camera);

}

void Enemy::move(bn::fixed_point_t<12> target){

    m_sprite.set_camera(m_camera);

    bn::fixed_point diff = target - m_sprite.position();

    diff = normalize_vector(diff);

    m_sprite.set_position(m_sprite.position() + (diff / 2));
}


bool Enemy::take_damage(int damage){
    m_health -= damage;
    if(m_health <= 0){
        return true;
    }

    return false;

}

void Enemy::randomize_position(){
    m_sprite.set_position(m_random->get_int() % 512 - 256, m_random->get_int() % 512 - 256);
}
