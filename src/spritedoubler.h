#ifndef SPRITEDOUBLER_H
#define SPRITEDOUBLER_H

#include <vector>
#include <algorithm>
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
class SpriteDoubler
{
public:
    SpriteDoubler();

    void add_sprite(bn::sprite_ptr spritedata);
    void delete_sprite(bn::sprite_ptr& sprite);
private:
    void update();

private:
    std::vector<bn::sprite_ptr> m_Sprites;
};

#endif // SPRITEDOUBLER_H
