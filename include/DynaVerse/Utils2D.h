#ifndef UTILS2D_H
#define UTILS2D_H

#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse2D.h"
#include "DynaVerse/CollisionDetection2D.h"

namespace DynaVerse {

    // Get AABB for a rigid body
    AABB getAABBForBody(const RigidBody2D& body);

} // namespace DynaVerse

#endif // UTILS2D_H