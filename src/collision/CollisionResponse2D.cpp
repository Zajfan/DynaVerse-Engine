#include "DynaVerse/CollisionResponse2D.h"

namespace DynaVerse {

    // Resolve collision between two circles
    void resolveCircleCircleCollision(RigidBody2D& body1, float radius1,
        RigidBody2D& body2, float radius2) {
        // Calculate collision normal
        Vector2D collisionNormal = (body2.position - body1.position);
        collisionNormal.normalize();

        // Calculate relative velocity
        Vector2D relativeVelocity = body2.linearVelocity - body1.linearVelocity;

        // Calculate impulse magnitude
        float impulseMagnitude = -(1 + 0.5f) * relativeVelocity.dot(collisionNormal) /
            (1 / body1.mass + 1 / body2.mass);

        // Apply impulses to the bodies
        body1.linearVelocity = body1.linearVelocity + (collisionNormal * impulseMagnitude / body1.mass);
        body2.linearVelocity = body2.linearVelocity - (collisionNormal * impulseMagnitude / body2.mass);
    }

    // Resolve collision between two AABBs
    void resolveAABBCollision(RigidBody2D& body1, const AABB& aabb1,
        RigidBody2D& body2, const AABB& aabb2) {
        // 1. Find the collision normal and penetration depth

        Vector2D center1 = (aabb1.min + aabb1.max) / 2.0f;
        Vector2D center2 = (aabb2.min + aabb2.max) / 2.0f;
        Vector2D distance = center2 - center1;

        Vector2D minDistance = (aabb1.max - aabb1.min) / 2.0f + (aabb2.max - aabb2.min) / 2.0f;

        Vector2D penetration = minDistance - Vector2D(fabs(distance.x), fabs(distance.y));

        // Choose the axis with the smallest penetration
        Vector2D collisionNormal;
        if (penetration.x < penetration.y) {
            collisionNormal = Vector2D(distance.x < 0 ? -1.0f : 1.0f, 0);
        }
        else {
            collisionNormal = Vector2D(0, distance.y < 0 ? -1.0f : 1.0f);
        }

        // 2. Resolve interpenetration (optional, depends on your needs)

        float correctionMagnitude = 0.5f * fmax(penetration.x, penetration.y); // Adjust as needed
        body1.position = body1.position - collisionNormal * correctionMagnitude / 2.0f;
        body2.position = body2.position + collisionNormal * correctionMagnitude / 2.0f;

        // 3. Apply impulse-based collision response

        // Calculate relative velocity
        Vector2D relativeVelocity = body2.linearVelocity - body1.linearVelocity;

        // Calculate impulse magnitude
        float impulseMagnitude = -(1 + 0.5f) * relativeVelocity.dot(collisionNormal) /
            (1 / body1.mass + 1 / body2.mass);

        // Apply impulses to the bodies
        body1.linearVelocity = body1.linearVelocity + (collisionNormal * impulseMagnitude / body1.mass);
        body2.linearVelocity = body2.linearVelocity - (collisionNormal * impulseMagnitude / body2.mass);
    }

} // namespace DynaVerse