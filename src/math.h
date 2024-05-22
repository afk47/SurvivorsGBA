#ifndef MATH_H
#define MATH_H

#endif // MATH_H

#include "bn_core.h"
#include "bn_math.h"

#include "bn_fixed_point.h"

constexpr bn::fixed_t<12> M_PI   = 3.141592653589793;
constexpr bn::fixed_t<12> M_PI_2 = 1.5707963267948966;
constexpr bn::fixed_t<12> M_PI_4 = 0.7853981633974483;
constexpr bn::fixed_t<12> M_RADIAN_DEG = 57.2957795131;


static bn::fixed_point normalizeVector(bn::fixed_point vector){

    bn::fixed_t<12> magnitude = bn::sqrt(vector.x() * vector.x() + vector.y()* vector.y());

    if (magnitude == 0){ //prevent divide by zero
        return vector;
    }

    vector = vector.division(magnitude);

    return vector;
}


static bn::fixed_t<12> fastArcTanDeg(bn::fixed_t<12> x){
    bn::fixed_t<12> fatrad = M_PI_4 * x - x * ((x >= 0) ? x : -x - 1) * (0.2447 + 0.0663 * (x >= 0) ? x : -x);
    return fatrad * M_RADIAN_DEG;

}


