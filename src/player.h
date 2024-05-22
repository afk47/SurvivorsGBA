#ifndef PLAYER_H
#define PLAYER_H


#include "bn_sprite_ptr.h"

class Player
{
public:
    Player();
    void Update();
    inline bn::fixed_point position(){ return sprite.position(); }
private:
    void Move();

private:
    bn::sprite_ptr sprite;
    int facing;
};

#endif // PLAYER_H
