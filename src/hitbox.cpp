#include "hitbox.h"

Hitbox::Hitbox(Rect dim): p_dimensions(dim),m_center(center(p_dimensions)){


}


bool Hitbox::collides(Hitbox other){
    if(!m_active || !other.is_active())
        return false;

    return collision_AABB(p_dimensions, other.p_dimensions);
}

bool Hitbox::is_inside(const bn::fixed_point point){
    if(!m_active)
        return false;

    return (point.x() > p_dimensions.x &&
            point.x() < p_dimensions.x + p_dimensions.w &&
            point.y() > p_dimensions.y &&
            point.y() < p_dimensions.y + p_dimensions.h );
}











