#include "spritedoubler.h"
#include "bn_hdma.h"
#include "bn_sprites.h"
#include "bn_unique_ptr.h"
#include "bn_display.h"

//for sorting vector by height
bool compareSpriteHeight(const bn::sprite_ptr& a, const bn::sprite_ptr& b){
    return a.y() < b.y();
}

SpriteDoubler::SpriteDoubler() {}

void SpriteDoubler::add_sprite(bn::sprite_ptr sprite){
    m_Sprites.push_back(sprite);
    std::sort(m_Sprites.begin(),m_Sprites.end(), compareSpriteHeight);
}

void SpriteDoubler::delete_sprite(bn::sprite_ptr& sprite){
    m_Sprites.erase(std::remove(m_Sprites.begin(),m_Sprites.end(),sprite));
}


void SpriteDoubler::update(){
    int availableSlots = 128 - bn::sprites::used_items_count();



}



