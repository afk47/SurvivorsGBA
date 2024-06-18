#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "bn_fixed.h"
#include "bn_sprite_item.h"

//Minimal data needed to instantiate a new sprite
struct Entity{
    bn::fixed x,y;
    bn::sprite_item sprite;
};


#endif // ENTITY_H
