#ifndef LEVELUPMENU_H
#define LEVELUPMENU_H
#include "scene.h";
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"


class LevelUpMenu : Scene
{
public:
    LevelUpMenu(bn::sprite_text_generator textGenerator,int level);
    virtual void update();

private:
    void input();
    void upgrade(int selection);
private:
    bn::sprite_text_generator m_TextGenerator;
    bn::vector<bn::sprite_ptr, 65> m_TextSprites;
    int m_Selection = 0;
};
#endif // LEVELUPMENU_H
