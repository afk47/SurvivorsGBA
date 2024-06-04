#include "fightscene.h"

#include "bn_regular_bg_item.h"
#include "math.h"
#include "core.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_fightbg.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_display.h"
#include "bn_string.h"
#include "bn_fixed_point.h"
#include "common_variable_8x16_sprite_font.h"

FightScene::FightScene():
    bg(bn::regular_bg_items::fightbg.create_bg(0,0)),
    camera(bn::camera_ptr::create(0, 0)),
    player(Player(camera)),
    internalWindow(bn::rect_window::internal()),
    dimensions(bg.dimensions().width(),bg.dimensions().height()),
    padding(48,90),
    scoreboard(bn::sprite_text_generator(common::variable_8x16_sprite_font))

{

    scoreboard.set_left_alignment();

    const bn::regular_bg_map_item& map_item = bn::regular_bg_items::fightbg.map_item();

    for(int i = 0; i < 50; i++){
        enemies.push_back(Enemy(camera).set_random(&random));
        enemies[i].randomize_position();
    }

    bn::window outside_window = bn::window::outside();
    outside_window.set_show_bg(bg,false);


    bg.set_camera(camera);
    bg.set_priority(3);
    scoreboard.set_bg_priority(0);
    internalWindow.set_boundaries(-128, -128, 128, 128);
    internalWindow.set_camera(camera);
}

void FightScene::update()
{
    textSprites.clear();
    player.update();
    process_input();

    PlayerAction action = player.get_player_action();

    int i = 0;//enemy index
    // destroys enemy when close enough and player is attacking.
    for(bn::vector<Enemy,128>::const_iterator position = enemies.cbegin(); position < enemies.cend(); ++position)
    {
        enemies[i].move(camera.position() + player.p_sprite.position());
        bn::fixed_point diff = camera.position() + player.p_sprite.position() - enemies[i].position();
        if(action & PlayerAction::Attack)
        {

            if (diff.x() < 15 && diff.x() > -15 && diff.y() < 15 && diff.y() > -15)
            {
                if(enemies[i].take_damage(10)){
                    enemies.erase(position);
                    score += 100;
                }
            }
        }else if(diff.x() < 5 && diff.x() > -5 && diff.y() < 5 && diff.y() > -5){
            if(player.take_damage(100)){
                enemies.clear();
                game_over();
                break;
            }
        }
        ++i;
    }

    scoreboard.generate(-100 , -70, bn::to_string<32>(score), textSprites);



}

void FightScene::process_input()
{

    if(bn::keypad::left_held())
    {
        player.set_facing(2);
        if(-(dimensions.x() - bn::display::width()) / 2 > camera.x() - 1)
        {
            player.p_sprite.set_x(bn::max((-dimensions.x() / 2) + padding.x(), player.p_sprite.x() - 1));
        }
        camera.set_x(bn::max(-(dimensions.x() - bn::display::width()) / 2, camera.x() - 1));
    }
    else if(bn::keypad::right_held())
    {
        player.set_facing(3);
        if((dimensions.x() - bn::display::width()) / 2 < camera.x() + 1)
        {
            player.p_sprite.set_x(bn::min((dimensions.x() / 2) - padding.x(),player.p_sprite.x() + 1));
        }
        camera.set_x(bn::min((dimensions.x()- bn::display::width()) / 2,camera.x() + 1));
    }

    if(bn::keypad::up_held())
    {
        player.set_facing(0);
        if(-(dimensions.y() - bn::display::height()) / 2 > camera.y() - 1)
        {
            player.p_sprite.set_y(bn::max((-dimensions.y() / 2) + padding.y(), player.p_sprite.y() - 1));
        }
        camera.set_y(bn::max(-(dimensions.y() - bn::display::height()) / 2, camera.y() - 1));
    }
    else if(bn::keypad::down_held())
    {
        player.set_facing(1);
        if((dimensions.y() - bn::display::height()) / 2 < camera.y() + 1)
        {
            player.p_sprite.set_y(bn::min((dimensions.y() / 2) - padding.y(),player.p_sprite.y() + 1));
        }
        camera.set_y(bn::min((dimensions.y() - bn::display::height()) / 2,camera.y() + 1));
    }

    if(bn::keypad::a_pressed()){
        player.attack();
    }
}

void FightScene::game_over(){
    scoreboard.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);
    scoreboard.generate(0,-10,"GAME OVER!", textSprites);
    scoreboard.generate(0,0,bn::to_string<32>(score),textSprites);
    camera.set_position(0,0);
    player.p_sprite.set_visible(false);

    while(!bn::keypad::start_pressed()){
        bn::core::update();
    }

    score = 0;
    for(int i = 0; i < 50; i++){
        enemies.push_back(Enemy(camera).set_random(&random));
        enemies[i].randomize_position();
    }
    player.p_sprite.set_position(0,0);
    player.p_sprite.set_visible(true);


}
