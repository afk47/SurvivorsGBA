#pragma once
#ifndef MATH_H
#define MATH_H

#endif // MATH_H

#include "bn_core.h"
#include "bn_math.h"
#include "bn_fixed_point.h"


//constexpr bn::fixed_t<12> M_PI   = 3.141592653589793;
//constexpr bn::fixed_t<12> M_PI_2 = 1.5707963267948966;
//constexpr bn::fixed_t<12> M_PI_4 = 0.7853981633974483;
//constexpr bn::fixed_t<12> M_RADIAN_DEG = 57.2957795131;


struct Rect{
    bn::fixed_t<12> x,y,w,h;
};

struct Circle{ //TODO: Check if necessary.
    bn::fixed_t<12> x,y,r;
};

inline bn::fixed_point normalize_vector(bn::fixed_point vector){

    bn::fixed_t<12> magnitude = bn::sqrt(vector.x() * vector.x() + vector.y()* vector.y());

    if (magnitude == 0){ //prevent divide by zero
        return vector;
    }

    vector = vector.division(magnitude);

    return vector;
}


inline bn::fixed_t<12> fast_arc_tan_deg(bn::fixed_t<12> x){
//    bn::fixed_t<12> fatrad = M_PI_4 * x - x * ((x >= 0) ? x : -x - 1) * (0.2447 + 0.0663 * (x >= 0) ? x : -x);
//    return fatrad * M_RADIAN_DEG;

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

//Circle-Circle Collision, TODO: Check if necessary.
inline bool collision_circle(Circle circ1, Circle circ2)
{
    return (circ1.x - circ2.x)*(circ1.x - circ2.x) + (circ1.y - circ2.y)*(circ1.y - circ2.y)< (circ2.r + circ1.r)*(circ2.r + circ1.r);
}

// TODO: Circle-Rect TODO: Check if necessary.
inline bool collision_circle_rect(Rect rect, Circle circ){

    return false;
}

inline bn::fixed_point center(Rect rect){
    auto cX = (rect.x + rect.x + rect.w) / 2;
    auto cY = (rect.y + rect.y + rect.h) / 2;

    return {cX,cY};
}

