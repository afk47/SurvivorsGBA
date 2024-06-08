#pragma once
#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H

#include "bn_regular_bg_ptr.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "bn_camera_ptr.h"
#include "player.h"
#include "scene.h"
#include "enemy.h"
#include "bn_rect_window.h"
#include "bn_sprite_text_generator.h"

class FightScene : public Scene
{
public:
    FightScene();
    void update();
    void process_input();
private:
    void game_over();
    void wave_screen();
    void restart();
    void populate_wave();
private:
    Player m_Player;
    bn::vector<Enemy,128> m_Enemies;
    bn::regular_bg_ptr m_BG;
    bn::random m_Random;
    bn::camera_ptr m_Camera;
    bn::rect_window m_InternalWindow;
    bn::fixed_point_t<12> m_Dimensions;
    bn::fixed_point_t<12> m_Padding;
    bn::sprite_text_generator m_TextGenerator;
    bn::vector<bn::sprite_ptr, 32> m_TextSprites;
    int m_Score = 0;
    int m_Wave = 1;
};

#endif // FIGHTSCENE_H
