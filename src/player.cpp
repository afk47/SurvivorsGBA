#include "player.h"

#include "bn_sprite_items_goblin.h"
#include "bn_keypad.h"
#include "bn_sprite_builder.h"

Player::Player(const bn::camera_ptr& camera)
    :sprite(bn::sprite_items::goblin.create_sprite(0,0)),camera(camera)
{
    sprite.set_camera(camera);
}

void Player::update()
{
    move();



    if(actionTimer > 0){
        actionTimer--;
    }

    if(bn::keypad::a_pressed()){
        action = PlayerAction::Attack;
        actionTimer = 10;
    }else if(action & PlayerAction::Attack && actionTimer <= 0){
        action = PlayerAction::None;
        actionTimer = 0;
    }

    animate();

}



void Player::move()
{

    if(bn::keypad::up_held())
    {
        if(sprite.y() > - 10)
            sprite.set_y(sprite.y() - 1);
        facing = 0;
    }
    if(bn::keypad::down_held())
    {

        if(sprite.y() <  10)
            sprite.set_y(sprite.y() + 1);
        facing = 1;
    }
    if(bn::keypad::left_held())
    {
        if(sprite.x() > - 10)
            sprite.set_x(sprite.x() - 1);
        facing = 2;
    }
    if(bn::keypad::right_held())
    {
        if(sprite.x() < 10)
            sprite.set_x(sprite.x() + 1);
        facing = 3;

    }
}

void Player::animate(){

    if(action & PlayerAction::Attack){
        switch(facing){
        case 0:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(25));
            break;
        case 2:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(22));
            break;
        case 3:
        case 1:
        default:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(18));
            break;
        }

    }else{
        switch(facing){
        case 0:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(10));
            break;
        case 2:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(4));
            break;
        case 3:
        case 1:
        default:
            sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(0));
            break;
        }
    }
}


