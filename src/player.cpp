#include "player.h"

#include "bn_sprite_items_wizard.h"
#include "bn_sprite_items_fire_spin.h"
#include "bn_sprite_builder.h"


Player::Player(const bn::camera_ptr& camera)
    : m_Sound(&SoundController::getInstance()),
    p_Sprite(bn::sprite_items::wizard.create_sprite(0,0)),
    m_Camera(camera),
    m_Size_Hitbox(12),
    m_Size_Hurtbox(3),
    m_Hitbox({p_Sprite.x() - m_Size_Hitbox,p_Sprite.y()- m_Size_Hitbox,m_Size_Hitbox * 2,m_Size_Hitbox* 2}),
    m_Hurtbox({p_Sprite.x() - m_Size_Hurtbox,p_Sprite.y()- m_Size_Hurtbox,m_Size_Hurtbox* 2,m_Size_Hurtbox* 2}),
    m_SpellSprite(bn::sprite_items::fire_spin.create_sprite(0,0))
{
    m_SpellSprite.set_camera(camera);
    p_Sprite.set_camera(camera);
    m_SpellSprite.set_z_order(5);
    p_Sprite.set_z_order(1);
}

void Player::update()
{

    m_SpellSprite.set_position(p_Sprite.position());

    m_Hitbox.set_position({p_Sprite.x()-m_Size_Hitbox, p_Sprite.y()-m_Size_Hitbox});
    m_Hurtbox.set_position({p_Sprite.x()-m_Size_Hurtbox,p_Sprite.y()-m_Size_Hurtbox});



    if(m_Action_Timer > 0)
        m_Action_Timer--;


    if(m_Cooldown_Attack > 0)
        m_Cooldown_Attack--;

    if(m_Cooldown_Attack <= 0){
        attack();
    }


    if(m_Action & PlayerAction::Attack && m_Action_Timer <= 0){
        m_Action = PlayerAction::None;
        m_Hitbox.set_active(false);
    }

    if(m_Action & PlayerAction::Attack){
        m_SpellSprite.set_visible(true);
    }else{
        m_SpellSprite.set_visible(false);
    }
    animate();

}

void Player::attack(){
    if(m_Cooldown_Attack <= 0){
        m_Action = m_Action | PlayerAction::Attack;
        m_Action_Timer = 10;
        m_Cooldown_Attack = 30;
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


    if(m_Facing == 2){
        p_Sprite.set_horizontal_flip(true);
    }
    if(m_Facing == 3){
        p_Sprite.set_horizontal_flip(false);
    }
}


