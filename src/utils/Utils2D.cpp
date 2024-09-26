#include "DynaVerse/Utils2D.h"

namespace DynaVerse {

    AABB getAABBForBody(const RigidBody2D& body) {
        switch (body.shapeType) {
        case RigidBody2D::CIRCLE:
            return AABB{
                body.position - Vector2D(body.radius, body.radius),
                body.position + Vector2D(body.radius, body.radius)
            };
        case RigidBody2D::AABB:
            return AABB{
                body.position - body.size,
                body.position + body.size
            };
            // Add cases for other shapes as you implement them
        default:
            // Handle unsupported shapes (you might want to throw an exception or log an error)
            return AABB{};
        }
    }

} // namespace DynaVerse