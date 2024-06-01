#ifndef PLAYER_H
#define PLAYER_H

#include "core.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"


enum PlayerAction : uint8_t{
    None = 0,
    Attack = BIT(0),

};

class Player
{
public:
    Player(const bn::camera_ptr& camera);
    void update();
    inline bn::fixed_point position(){ return sprite.position(); }
    void set_camera(const bn::camera_ptr& camera){ sprite.set_camera(camera); this->camera = camera; }
    inline PlayerAction getPlayerAction(){ return action;}
private:
    void move();
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
