#ifndef COLLISIONDETECTION2D_H
#define COLLISIONDETECTION2D_H

#include "DynaVerse/math/Vector2D.h"

namespace DynaVerse {

    // Axis-Aligned Bounding Box (AABB)
    struct AABB {
        Vector2D min, max;
    };

    // Check for collision between two AABBs
    bool checkAABBCollision(const AABB& a, const AABB& b);

} // namespace DynaVerse

#endif // COLLISIONDETECTION2D_H