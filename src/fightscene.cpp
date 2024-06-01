#include "fightscene.h"

#include "bn_regular_bg_item.h"
#include "math.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_whitebg.h"
#include "bn_keypad.h"
#include "bn_log.h"

FightScene::FightScene()
    : bg(bn::regular_bg_items::whitebg.create_bg(0,0)), camera(bn::camera_ptr::create(0, 0)),player(Player(camera)),internal_window(bn::rect_window::internal())
{
    bg.set_visible(true);

    for(int i = 0; i < 5; i++){
        enemies.push_back(Enemy(camera).SetRandom(&random));
    }

    bg.set_camera(camera);
    internal_window.set_boundaries(-48, 8, 48, 104);
    internal_window.set_camera(camera);
}

void FightScene::update()
{
    player.update();
    processInput();

    PlayerAction action = player.getPlayerAction();

    int i = 0;//enemy index
    // destroys enemy when close enough and player is attacking.
    for(bn::vector<Enemy,50>::const_iterator position = enemies.cbegin(); position < enemies.cend(); ++position)
    {
        enemies[i].Move(camera.position() + player.position());
        if(action & PlayerAction::Attack)
        {
            bn::fixed_point diff = camera.position() + player.position() - enemies[i].position();
            if (diff.x() < 5 && diff.x() > -5 && diff.y() < 5 && diff.y() > -5)
            {
                if(enemies[i].takeDamage(10))
                    enemies.erase(position);
            }
        }
        ++i;
    }


}

void FightScene::processInput()
{

    if(bn::keypad::left_held())
    {
        camera.set_x(camera.x() - 1);
    }
    else if(bn::keypad::right_held())
    {
        camera.set_x(camera.x() + 1);
    }

    if(bn::keypad::up_held())
    {
        camera.set_y(camera.y() - 1);
    }
    else if(bn::keypad::down_held())
    {
        camera.set_y(camera.y() + 1);
    }
}
