

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
#include "bn_sprite_items_ball.h"
#include "bn_log.h"
#include "fightscene.h"


#include "math.h"
#include "player.h"

int main()
{
    bn::core::init();


    Scene* scene = new FightScene();

    while(true)
    {
        scene->Update();
        bn::core::update();

    }
}
