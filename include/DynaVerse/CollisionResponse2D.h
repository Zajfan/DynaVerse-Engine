#ifndef COLLISIONRESPONSE2D_H
#define COLLISIONRESPONSE2D_H

#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse2D.h"
#include "DynaVerse/CollisionDetection2D.h"

namespace DynaVerse {

    // Resolve collision between two circles
    void resolveCircleCircleCollision(RigidBody2D& body1, float radius1,
        RigidBody2D& body2, float radius2);

    // Resolve collision between two AABBs
    void resolveAABBCollision(RigidBody2D& body1, const AABB& aabb1,
        RigidBody2D& body2, const AABB& aabb2);

} // namespace DynaVerse

#endif // COLLISIONRESPONSE2D_H