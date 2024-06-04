#include "player.h"

#include "bn_sprite_items_goblin.h"
#include "bn_keypad.h"
#include "bn_sprite_builder.h"

Player::Player(const bn::camera_ptr& camera)
    :p_sprite(bn::sprite_items::goblin.create_sprite(0,0)),camera(camera)
{
    p_sprite.set_camera(camera);
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

bool Player::take_damage(int damage){
    health -= damage;
    if(health <= 0){
        health = 0;
        return true;
    }
    return false;

}


void Player::animate(){

    if(action & PlayerAction::Attack){
        switch(facing){
        case 0:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(25));
            break;
        case 2:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(22));
            break;
        case 3:
        case 1:
        default:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(18));
            break;
        }

    }else{
        switch(facing){
        case 0:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(10));
            break;
        case 2:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(4));
            break;
        case 3:
        case 1:
        default:
            p_sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(0));
            break;
        }
    }
}


