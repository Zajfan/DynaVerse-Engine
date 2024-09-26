#include "DynaVerse/CollisionDetection2D.h"

namespace DynaVerse {

    bool checkAABBCollision(const AABB& a, const AABB& b) {
        return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
            (a.min.y <= b.max.y && a.max.y >= b.min.y);
    }

} // namespace DynaVerse