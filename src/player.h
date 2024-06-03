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

    inline bn::fixed_point position(){ return sprite.position(); }
    inline bn::fixed y(){ return sprite.y();}
    inline bn::fixed x(){ return sprite.x();}

    void set_position(const bn::fixed_point &position){ sprite.set_position(position); }
    void set_y(const bn::fixed val){ sprite.set_y(val); }
    void set_x(const bn::fixed val){ sprite.set_x(val); }
    void set_facing(int direction){
        if(direction > 3 || direction < 0)
            return;
        facing = direction;
    }

    void set_camera(const bn::camera_ptr& camera){ sprite.set_camera(camera); this->camera = camera; }
    inline PlayerAction getPlayerAction(){ return action;}
    void attack();
private:

    void animate();

private:
    bn::sprite_ptr sprite;
    int facing;
    PlayerAction action = PlayerAction::None;
    int actionTimer = 0;
    bn::camera_ptr camera;

    int animationFrames = 0;
    int frameOfAnim = 0;

};



#endif // PLAYER_H
