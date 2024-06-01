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

class FightScene : public Scene
{
public:
    FightScene();
    void update();
    void processInput();

private:
    Player player;
    bn::vector<Enemy,50> enemies;
    bn::regular_bg_ptr bg;
    bn::random random;
    bn::camera_ptr camera;
    bn::rect_window internal_window;
};

#endif // FIGHTSCENE_H
