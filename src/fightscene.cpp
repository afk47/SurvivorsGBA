#include "fightscene.h"

#include "bn_regular_bg_item.h"
#include "math.h"
#include "core.h"
#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_items_fightbg.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_display.h"

#include "bn_fixed_point.h"
FightScene::FightScene():
    bg(bn::affine_bg_items::fightbg.create_bg(0,0)),
    camera(bn::camera_ptr::create(0, 0)),
    player(Player(camera)),
    internal_window(bn::rect_window::internal()),
    dimensions(bg.dimensions().width(),bg.dimensions().height()),
    padding(48)
{
    bg.set_visible(true);


    for(int i = 0; i < 110; i++){
        enemies.push_back(Enemy(camera).SetRandom(&random));
    }


    bn::window outside_window = bn::window::outside();
    outside_window.set_show_bg(bg,false);

    bg.set_camera(camera);
    internal_window.set_boundaries(-128, -128, 128, 128);
    internal_window.set_camera(camera);

}

void FightScene::update()
{
    player.update();
    processInput();

    PlayerAction action = player.getPlayerAction();

    int i = 0;//enemy index
    // destroys enemy when close enough and player is attacking.
    for(bn::vector<Enemy,128>::const_iterator position = enemies.cbegin(); position < enemies.cend(); ++position)
    {
        enemies[i].Move(camera.position() + player.position());
        if(action & PlayerAction::Attack)
        {
            bn::fixed_point diff = camera.position() + player.position() - enemies[i].position();
            if (diff.x() < 15 && diff.x() > -15 && diff.y() < 15 && diff.y() > -15)
            {
                if(enemies[i].takeDamage(10))
                    enemies[i].RandomizePosition();//enemies.erase(position);
            }
        }
        ++i;
    }


}

void FightScene::processInput()
{
    BN_LOG("Player Position:\t", player.x(), "\t",player.y());
    BN_LOG("World Dimensions:", dimensions.x(), "\t",dimensions.y());
    if(bn::keypad::left_held())
    {
        player.set_facing(2);
        player.set_x(bn::max((-dimensions.x() / 2) + padding, player.x() - 1));
        camera.set_x(bn::max(-(dimensions.x() - bn::display::width()) / 2, camera.x() - 1));
    }
    else if(bn::keypad::right_held())
    {
        player.set_facing(3);
        player.set_x(bn::min((dimensions.x() / 2) - padding,player.x() + 1));
        camera.set_x(bn::min((dimensions.x()- bn::display::width()) / 2,camera.x() + 1));
    }

    if(bn::keypad::up_held())
    {
        player.set_facing(0);
        player.set_y(bn::max((-dimensions.y() / 2) + padding, player.y() - 1));
        camera.set_y(bn::max(-(dimensions.y() - bn::display::height()) / 2, camera.y() - 1));
    }
    else if(bn::keypad::down_held())
    {
        player.set_facing(1);
        player.set_y(bn::min((dimensions.y() / 2) - padding,player.y() + 1));
        camera.set_y(bn::min((dimensions.y() - bn::display::height()) / 2,camera.y() + 1));
    }

    if(bn::keypad::a_pressed()){
        player.attack();
    }
}
