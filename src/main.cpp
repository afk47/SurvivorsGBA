#include "bn_camera_ptr.h"
#include "bn_core.h" // Core libraries.

#include "fightscene.h"

int main()
{
    bn::core::init();
    SoundController& sound = SoundController::getInstance();
    Scene* scene = new FightScene(sound);
    //Scene* scene = new Scene();

    while(true)
    {
        scene->update();


    }
}

