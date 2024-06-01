#include "bn_core.h" // Core libraries.

#include "fightscene.h"

#include "math.h"




int main()
{
    bn::core::init();


    Scene* scene = new FightScene();

    while(true)
    {
        scene->update();
        bn::core::update();

    }
}

