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
private:
    Player player;
    bn::vector<Enemy,128> enemies;
    bn::regular_bg_ptr bg;
    bn::random random;
    bn::camera_ptr camera;
    bn::rect_window internalWindow;
    bn::fixed_point_t<12> dimensions;
    bn::fixed_point_t<12> padding;
    bn::sprite_text_generator scoreboard;
    bn::vector<bn::sprite_ptr, 32> textSprites;
    int score = 0;
};

#endif // FIGHTSCENE_H
