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
 //   move();



    if(actionTimer > 0){
        actionTimer--;
    }


    if(action & PlayerAction::Attack && actionTimer <= 0){
        action = PlayerAction::None;
        actionTimer = 0;
    }

    animate();

}

void Player::attack(){
    action = action | PlayerAction::Attack;
    actionTimer = 10;
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


