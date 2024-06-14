#ifndef PLAYER_H
#define PLAYER_H

#include "core.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"
#include "hitbox.h"
#include "sound.h"

enum PlayerAction{
    None = 0,
    Attack = BIT(0),

};

inline PlayerAction operator|(PlayerAction a, PlayerAction b)
{
    return static_cast<PlayerAction>(static_cast<int>(a) | static_cast<int>(b));
}

class Player
{
public:
    Player(const bn::camera_ptr& camera);

    void update();
    void attack();
    bool take_damage(int damage); //true if dead



    //Getters and Setters
    inline PlayerAction get_player_action(){ return m_Action;}
    void set_facing(int direction){
        if(direction > 3 || direction < 0)
            return;
        m_Facing = direction;
    }
    Hitbox get_hitbox(){return m_Hitbox;}

    Hitbox get_hurtbox(){return m_Hurtbox;}
private:

    void animate();

public:
    bn::sprite_ptr p_Sprite;

private:
    SoundController* m_Sound;
    bn::camera_ptr m_Camera;
    int m_Facing;
    PlayerAction m_Action = PlayerAction::None;
    int m_Action_Timer = 0;
    int m_Cooldown = 0;
    int m_Health = 100;
    bn::fixed m_Size_Hitbox;
    bn::fixed m_Size_Hurtbox;
    Hitbox m_Hitbox;
    Hitbox m_Hurtbox;
};



#endif // PLAYER_H
