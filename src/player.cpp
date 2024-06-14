#include "player.h"

#include "bn_sprite_items_goblin.h"
#include "bn_sprite_builder.h"


Player::Player(const bn::camera_ptr& camera)
    : m_Sound(&SoundController::getInstance()),
    p_Sprite(bn::sprite_items::goblin.create_sprite(0,0)),
    m_Camera(camera),
    m_Size_Hitbox(10),
    m_Size_Hurtbox(3),
    m_Hitbox({p_Sprite.x() - m_Size_Hitbox,p_Sprite.y()- m_Size_Hitbox,m_Size_Hitbox * 2,m_Size_Hitbox* 2}),
    m_Hurtbox({p_Sprite.x() - m_Size_Hurtbox,p_Sprite.y()- m_Size_Hurtbox,m_Size_Hurtbox* 2,m_Size_Hurtbox* 2})
{
    p_Sprite.set_camera(camera);

}

void Player::update()
{


    m_Hitbox.set_position({p_Sprite.x()-m_Size_Hitbox, p_Sprite.y()-m_Size_Hitbox});
    m_Hurtbox.set_position({p_Sprite.x()-m_Size_Hurtbox,p_Sprite.y()-m_Size_Hurtbox});


    if(m_Action_Timer > 0)
        m_Action_Timer--;


    if(m_Cooldown > 0)
        m_Cooldown--;


    if(m_Action & PlayerAction::Attack && m_Action_Timer <= 0){
        m_Action = PlayerAction::None;
        m_Hitbox.set_active(false);
    }

    animate();

}

void Player::attack(){
    if(m_Cooldown <= 0){
        m_Action = m_Action | PlayerAction::Attack;
        m_Action_Timer = 10;
        m_Cooldown = 30;
        m_Hitbox.set_active(true);
        m_Sound->play_sound(bn::sound_items::slash);
    }
}

bool Player::take_damage(int damage){
    m_Sound->play_sound(bn::sound_items::damage, 100, 1);
    m_Health -= damage;
    if(m_Health <= 0){
        m_Health = 0;
        return true;
    }
    return false;

}


void Player::animate(){

    if(m_Action & PlayerAction::Attack ){
        switch(m_Facing){
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
        switch(m_Facing){
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


