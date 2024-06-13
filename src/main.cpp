#include "bn_camera_ptr.h"
#include "bn_core.h" // Core libraries.

#include "fightscene.h"

// #include "bn_camera_ptr.h"
// #include "bn_sprite_ptr.h"
// #include "bn_sprite_items_ball.h" //Use a sprite here
// #include "bn_vector.h"
// #include "bn_keypad.h"
// #include "bn_regular_bg_ptr.h"
// #include "bn_regular_bg_items_fightbg.h" //use a regular bg here


// class SpriteContainer{
// public:
//     SpriteContainer(const bn::camera_ptr& cam)
//         : camera(cam), sprite(bn::sprite_items::ball.create_sprite(0,0))
//     {
//         sprite.set_camera(camera);
//     }
//     bn::camera_ptr camera;
//     bn::sprite_ptr sprite;
// };

// class Scene{
// public:
//     Scene()
//         : camera(bn::camera_ptr::create(0,0)), headerContainer(SpriteContainer(camera)), bg(bn::regular_bg_items::fightbg.create_bg(0,0))
//     {
//         bodyContainers.push_back(SpriteContainer(camera));
//         bodyContainers[0].sprite.set_position(0,10);
//         bg.set_camera(camera);
//     }

//     void update(){

//         bn::core::update();

//         if(bn::keypad::up_held()){
//             camera.set_y(camera.y()+10);
//         }
//         if(bn::keypad::down_held()){
//             camera.set_y(camera.y()-10);
//         }
//         if(bn::keypad::left_held()){
//             camera.set_x(camera.x()+10);
//         }
//         if(bn::keypad::right_held()){
//             camera.set_x(camera.x()-10);
//         }

//         if(bn::keypad::a_held()){
//             headerContainer.sprite.set_x(headerContainer.sprite.x() + 1);
//         }
//         if(bn::keypad::b_held()){
//             headerContainer.sprite.set_x(headerContainer.sprite.x() - 1);
//         }
//     }

//     bn::regular_bg_ptr bg;
//     bn::camera_ptr camera;
//     SpriteContainer headerContainer;
//     bn::vector<SpriteContainer,2> bodyContainers;
// };

int main()
{
    bn::core::init();

    Scene* scene = new FightScene();
    //Scene* scene = new Scene();

    while(true)
    {
        scene->update();


    }
}

