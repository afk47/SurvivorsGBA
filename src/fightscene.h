#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H

#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_ptr.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "bn_camera_ptr.h"
#include "player.h"
#include "scene.h"
#include "enemy.h"
#include "bn_rect_window.h"


class FightScene : public Scene
{
public:
    FightScene();
    void update();
    void processInput();

private:
    Player player;
    bn::vector<Enemy,128> enemies;
    bn::affine_bg_ptr bg;
    bn::random random;
    bn::camera_ptr camera;
    bn::rect_window internal_window;
    bn::fixed_point_t<12> dimensions;
    bn::fixed padding;
};

#endif // FIGHTSCENE_H
