#ifndef PLAYER_H
#define PLAYER_H

#include "core.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"


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
    void set_facing(int direction){
        if(direction > 3 || direction < 0)
            return;
        facing = direction;
    }
    inline PlayerAction get_player_action(){ return action;}
    void attack();
    bool take_damage(int damage);

private:

    void animate();

public:
    bn::sprite_ptr p_sprite;
private:
    int facing;
    PlayerAction action = PlayerAction::None;
    int actionTimer = 0;
    bn::camera_ptr camera;

    int animationFrames = 0;
    int frameOfAnim = 0;
    int health = 100;
};



#endif // PLAYER_H
