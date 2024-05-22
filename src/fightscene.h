#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H

#include "bn_regular_bg_ptr.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "player.h"
#include "scene.h"
#include "enemy.h"

class FightScene : public Scene
{
public:
    FightScene();
    void Update();

private:
    Player player;
    bn::vector<Enemy,50> enemies;
    bn::regular_bg_ptr bg;
    bn::random random;
};

#endif // FIGHTSCENE_H
