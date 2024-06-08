#include "player.h"

#include "bn_sprite_items_goblin.h"
#include "bn_sprite_builder.h"

Player::Player(const bn::camera_ptr& camera)
    :p_Sprite(bn::sprite_items::goblin.create_sprite(0,0)),
    m_camera(camera),
    m_size_hitbox(10),
    m_size_hurtbox(5),
    m_hitbox({p_Sprite.x() - m_size_hitbox,p_Sprite.y()- m_size_hitbox,p_Sprite.x() + m_size_hitbox,p_Sprite.y() + m_size_hitbox}),
    m_hurtbox({p_Sprite.x() - m_size_hurtbox,p_Sprite.y()- m_size_hurtbox,p_Sprite.x() + m_size_hurtbox,p_Sprite.y() + m_size_hurtbox})
{
    p_Sprite.set_camera(camera);

}

void Player::update()
{
 //   move();

    m_hitbox.set_position({p_Sprite.x()-m_size_hitbox,p_Sprite.y()-m_size_hitbox});
    m_hurtbox.set_position({p_Sprite.x()-m_size_hurtbox,p_Sprite.y()-m_size_hurtbox});


    if(m_action_timer > 0)
        m_action_timer--;


    if(m_cooldown > 0)
        m_cooldown--;


    if(m_action & PlayerAction::Attack && m_action_timer <= 0){
        m_action = PlayerAction::None;
        m_hitbox.set_active(false);
    }

    animate();

}

void Player::attack(){
    if(m_cooldown <= 0){
        m_action = m_action | PlayerAction::Attack;
        m_action_timer = 10;
        m_cooldown = 30;
        m_hitbox.set_active(true);
    }
}

bool Player::take_damage(int damage){
    m_health -= damage;
    if(m_health <= 0){
        m_health = 0;
        return true;
    }
    return false;

}


void Player::animate(){

    if(m_action & PlayerAction::Attack ){
        switch(m_facing){
        case 0:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(25));
            break;
        case 2:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(22));
            break;
        case 3:
        case 1:
        default:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(18));
            break;
        }

    }else{
        switch(m_facing){
        case 0:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(10));
            break;
        case 2:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(4));
            break;
        case 3:
        case 1:
        default:
            p_Sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(0));
            break;
        }
    }
}


