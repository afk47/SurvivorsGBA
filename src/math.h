#pragma once
#ifndef MATH_H
#define MATH_H

#endif // MATH_H

#include "bn_core.h"
#include "bn_math.h"
#include "bn_fixed_point.h"


struct Rect{
    bn::fixed_t<12> x,y,w,h;
};



inline bn::fixed_point normalize_vector(bn::fixed_point vector){

    bn::fixed_t<12> magnitude = bn::sqrt(vector.x() * vector.x() + vector.y()* vector.y());

    if (magnitude == 0){ //prevent divide by zero
        return vector;
    }

    vector = vector.division(magnitude);

    return vector;
}


//Rect - Rect Collision
inline bool collision_AABB(Rect rect1, Rect rect2)
{
    return
        (
            rect1.x < rect2.x + rect2.w &&
            rect1.x + rect1.w > rect2.x &&
            rect1.y < rect2.y + rect2.h &&
            rect1.y + rect1.h > rect2.y
            );

}



inline bn::fixed_point center(Rect rect){
    auto cX = (rect.x + rect.x + rect.w) / 2;
    auto cY = (rect.y + rect.y + rect.h) / 2;

    return {cX,cY};
}

