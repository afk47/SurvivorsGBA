
#include "enemy.h"

#include "math.h"


Enemy::Enemy(const bn::camera_ptr& camera)
    :  m_Sprite(bn::sprite_items::ball.create_sprite(0,0)),
    m_Health(10),
    m_Camera(camera),
    m_Speed(0.3)
{

    m_Sprite.set_position(0,0);
    m_Sprite.set_camera(m_Camera);

}

Enemy::Enemy(const bn::camera_ptr& camera,bn::sprite_item sprite)
    :  m_Sprite(sprite.create_sprite(0,0)),
    m_Health(10),
    m_Camera(camera),
    m_Speed(0.3)
{

    m_Sprite.set_position(0,0);
    m_Sprite.set_camera(m_Camera);

}

void Enemy::move(bn::fixed_point_t<12> target){

    m_Sprite.set_camera(m_Camera);

    bn::fixed_point diff = target - m_Sprite.position();

    diff = normalize_vector(diff);

    m_Sprite.set_position(m_Sprite.position() + (diff * m_Speed));
}


bool Enemy::take_damage(int damage){
    m_Health -= damage;
    if(m_Health <= 0){
        return true;
    }

    return false;

}

void Enemy::randomize_position(){
    m_Sprite.set_position(m_Random->get_int() % 512 - 256, m_Random->get_int() % 512 - 256);
}
