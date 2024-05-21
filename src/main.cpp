

#include "bn_core.h" // Core libraries.
#include "bn_display.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_keypad.h"
#include "bn_math.h"
#include "bn_sprite_builder.h"
#include "bn_regular_bg_items_whitebg.h"
#include "bn_sprite_items_goblin.h"
#include "bn_log.h"




int main()
{
    bn::core::init();

    bn::sprite_ptr player = bn::sprite_items::goblin.create_sprite(0,0);


    bn::regular_bg_ptr bg = bn::regular_bg_items::whitebg.create_bg(0,0);


    while(true)
    {
        bn::core::update();


        if(bn::keypad::up_held())
        {
            player.set_position(player.position().x(),player.position().y()-1);
            player.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(1));
        }
        if(bn::keypad::down_held())
        {
            player.set_position(player.position().x(),player.position().y()+1);
            player.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(0));
        }
        if(bn::keypad::left_held())
        {
            player.set_position(player.position().x()-1,player.position().y());
            player.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(2));
            player.set_vertical_flip(true);
        }
        if(bn::keypad::right_held())
        {
            player.set_position(player.position().x()+1,player.position().y());
            player.set_tiles(bn::sprite_items::goblin.tiles_item().create_tiles(2));
            player.set_vertical_flip(false);
        }
        player.set_rotation_angle(90);




    }
}
