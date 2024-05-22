#include "player.h"

#include "bn_sprite_items_goblin.h"
#include "bn_keypad.h"
#include "bn_sprite_builder.h"

Player::Player()
    :sprite(bn::sprite_items::goblin.create_sprite(0,0))
{
}

void Player::Update()
{
    Move();

    sprite.set_rotation_angle(90);
}

void Player::Move()
{
    if(bn::keypad::up_held())
    {
        sprite.set_y(sprite.y() - 1);
        facing = 0;
        sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(1));
    }
    if(bn::keypad::down_held())
    {
        sprite.set_y(sprite.y() + 1);
        facing = 1;
        sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(0));
    }
    if(bn::keypad::left_held())
    {
        sprite.set_x(sprite.x() - 1);
        facing = 2;
        sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(2));
        sprite.set_vertical_flip(true);
    }
    if(bn::keypad::right_held())
    {
        sprite.set_x(sprite.x() + 1);
        facing = 3;
        sprite.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(2));
        sprite.set_vertical_flip(false);
    }
}


