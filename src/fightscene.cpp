#include "fightscene.h"

#include "bn_regular_bg_item.h"
#include "core.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_fightbg.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_display.h"
#include "bn_string.h"
#include "bn_fixed_point.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprites.h"

FightScene::FightScene(SoundController& sound):
    m_Sound(sound),
    m_Camera(bn::camera_ptr::create(0, 0)),
    m_Player(Player(m_Camera)),
    m_BG(bn::regular_bg_items::fightbg.create_bg(0,0)),
    m_InternalWindow(bn::rect_window::internal()),
    m_Dimensions(m_BG.dimensions().width(),m_BG.dimensions().height()),
    m_Padding(36,36),
    m_TextGenerator(bn::sprite_text_generator(common::variable_8x16_sprite_font))

{

    m_TextGenerator.set_left_alignment();


    m_Player = Player(m_Camera);
    for(int i = 0; i < 50; i++){
        m_Enemies.push_back(Enemy(m_Camera).set_random(&m_Random));
        m_Enemies[i].randomize_position();
    }

    bn::window outside_window = bn::window::outside();
    outside_window.set_show_bg(m_BG,false);


    m_BG.set_camera(m_Camera);
    m_BG.set_priority(3);
    m_TextGenerator.set_bg_priority(0);
    m_InternalWindow.set_boundaries(-128, -128, 128, 128);
    m_InternalWindow.set_camera(m_Camera);
    m_Sound.play_music();

}

void FightScene::update()
{

    bn::core::update();
    m_TextSprites.clear();
    m_Player.update();
    process_input();
    m_Sound.update_music();

    PlayerAction action = m_Player.get_player_action();



    int idx = 0;//enemy index
    //Checks for collisions, if performance suffers look into other methods of
    for(bn::vector<Enemy,128>::const_iterator position = m_Enemies.cbegin(); position < m_Enemies.cend(); ++position)
    {
        m_Enemies[idx].move(m_Player.p_Sprite.position());

        if(action & PlayerAction::Attack)
        {


            if (m_Player.get_hitbox().is_inside(m_Enemies[idx].position()))
            {
                if(m_Enemies[idx].take_damage(5)){
                    m_Enemies.erase(position);
                    m_Score += 100;
                }
            }
        }else if(m_Player.get_hurtbox().is_inside(m_Enemies[idx].position())){
            if(m_Player.take_damage(100)){
                m_Enemies.clear();
                game_over();
                break;
            }
        }
        ++idx;
    }



    m_TextGenerator.generate(-100 , -70, bn::to_string<10>(m_Score), m_TextSprites);
    int availableSprites = 128 - bn::sprites::used_items_count();

    if(m_Enemies.empty()){
        wave_screen();
    }



}

void FightScene::process_input()
{

    if(bn::keypad::left_held())
    {
        m_Player.set_facing(2);

        m_Player.p_Sprite.set_x(bn::max((-m_Dimensions.x() / 2) + m_Padding.x(), m_Player.p_Sprite.x() - 1));

        m_Camera.set_x(bn::max(-(m_Dimensions.x() - bn::display::width()) / 2, m_Camera.x() - 1));
    }
    else if(bn::keypad::right_held())
    {
        m_Player.set_facing(3);
        m_Player.p_Sprite.set_x(bn::min((m_Dimensions.x() / 2) - m_Padding.x(),m_Player.p_Sprite.x() + 1));

        m_Camera.set_x(bn::min((m_Dimensions.x()- bn::display::width()) / 2,m_Camera.x() + 1));
    }

    if(bn::keypad::up_held())
    {
        m_Player.set_facing(0);

        m_Player.p_Sprite.set_y(bn::max((-m_Dimensions.y() / 2) + m_Padding.y(), m_Player.p_Sprite.y() - 1));

        m_Camera.set_y(bn::max(-(m_Dimensions.y() - bn::display::height()) / 2, m_Camera.y() - 1));
    }
    else if(bn::keypad::down_held())
    {
        m_Player.set_facing(1);

        m_Player.p_Sprite.set_y(bn::min((m_Dimensions.y() / 2) - m_Padding.y(),m_Player.p_Sprite.y() + 1));

        m_Camera.set_y(bn::min((m_Dimensions.y() - bn::display::height()) / 2,m_Camera.y() + 1));
    }

    if(bn::keypad::a_pressed()){
        m_Player.attack();
    }

    if(bn::keypad::select_pressed()){
        restart();
    }
}

void FightScene::game_over(){
    m_TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);
    m_TextGenerator.generate(0,-10,"GAME OVER!", m_TextSprites);
    m_TextGenerator.generate(0,0,bn::to_string<10>(m_Score),m_TextSprites);
    m_Camera.set_position(0,0);
    m_Player.p_Sprite.set_visible(false);
    m_Sound.set_music(bn::music_items::necromancerscastle);
    while(!bn::keypad::start_pressed()){
        bn::core::update();
    }


    restart();

}

void FightScene::restart(){
    m_Score = 0;

    m_Sound.set_music(bn::music_items::castle8bit);
    for(int i = 0; i < 50; i++){
        m_Enemies.push_back(Enemy(m_Camera).set_random(&m_Random));
        m_Enemies[i].randomize_position();
    }
    m_Player.p_Sprite.set_position(0,0);
    m_Player.p_Sprite.set_visible(true);
}

void FightScene::wave_screen(){
    for(int i = 0; i < WAVE_SCREEN_TIMER; i++){ //Wait on wave screen for WAVE_SCREEN_TIMER frames
        m_TextSprites.clear();
        m_TextGenerator.generate(-100 , -70, bn::to_string<10>(m_Score), m_TextSprites);
        m_TextGenerator.generate(0,-10,"WAVE " + bn::to_string<6>(m_Wave),m_TextSprites);
        bn::core::update();
    }
    populate_wave();
    ++m_Wave;

}

void FightScene::populate_wave(){
    int availableSprites = 128 - bn::sprites::used_items_count();
    BN_LOG(availableSprites);
    int nextWaveEnemies = m_Random.get_int() % (availableSprites % 100 - 40) + 20;

    for(int i = 0; i < nextWaveEnemies; i++){
        availableSprites = 128 - bn::sprites::used_items_count();
        BN_LOG(availableSprites);
        m_Enemies.push_back(Enemy(m_Camera).set_random(&m_Random));
        m_Enemies[i].randomize_position();
        bn::fixed_point diff = m_Camera.position() + m_Player.p_Sprite.position() - m_Enemies[i].position();
        if (diff.x() < 15 && diff.x() > -15 && diff.y() < 15 && diff.y() > -15)
        {
            m_Enemies[i].move(m_Enemies[i].position() - diff);
        }
    }


}
