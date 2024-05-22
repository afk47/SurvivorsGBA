#include "fightscene.h"

#include "bn_regular_bg_item.h"
#include "math.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_whitebg.h"

FightScene::FightScene()
    : bg(bn::regular_bg_items::whitebg.create_bg(0,0))
{


    player = Player();

    bg.set_visible(true);

    for(int i = 0; i < 40; i++){
        enemies.push_back(Enemy().SetRandom(&random));
    }
}

void FightScene::Update(){
    player.Update();

    for(auto enemy : enemies){
        enemy.Move(player.position());
    }
}
