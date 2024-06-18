#include "hitbox.h"

Hitbox::Hitbox(Rect dim): p_Dimensions(dim),m_Center(center(p_Dimensions)){


}


bool Hitbox::collides(Hitbox other){
    if(!m_Active || !other.is_active())
        return false;

    return collision_AABB(p_Dimensions, other.p_Dimensions);
}

bool Hitbox::is_inside(const bn::fixed_point point){
    if(!m_Active)
        return false;

    return (point.x() > p_Dimensions.x &&
            point.x() < p_Dimensions.x + p_Dimensions.w &&
            point.y() > p_Dimensions.y &&
            point.y() < p_Dimensions.y + p_Dimensions.h );
}











