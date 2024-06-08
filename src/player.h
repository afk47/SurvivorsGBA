#ifndef PLAYER_H
#define PLAYER_H

#include "core.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"
#include "hitbox.h"

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
    inline PlayerAction get_player_action(){ return m_action;}
    void set_facing(int direction){
        if(direction > 3 || direction < 0)
            return;
        m_facing = direction;
    }
    Hitbox get_hitbox(){return m_hitbox;}

    Hitbox get_hurtbox(){return m_hurtbox;}
private:

    void animate();

public:
    bn::sprite_ptr p_Sprite;

private:
    int m_facing;
    PlayerAction m_action = PlayerAction::None;
    int m_action_timer = 0;
    bn::camera_ptr m_camera;
    int m_cooldown = 0;
    int m_animation_frames = 0;
    int m_animation_frame = 0;
    int m_health = 100;
    bn::fixed m_size_hitbox;
    bn::fixed m_size_hurtbox;
    Hitbox m_hitbox;
    Hitbox m_hurtbox;
};



#endif // PLAYER_H
