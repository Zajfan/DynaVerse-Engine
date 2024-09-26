#ifndef DYNAVERSE2D_H
#define DYNAVERSE2D_H

#include <cmath>
#include "DynaVerse/math/Vector2D.h"

// 2D Rigid Body Class
class RigidBody2D {
public:
    float mass;
    float momentOfInertia;
    Vector2D position;
    float angle; // In radians
    Vector2D linearVelocity;
    float angularVelocity;

    // Add shape and size information
    enum ShapeType { CIRCLE, AABB, POLYGON }; // Add more types as needed
    ShapeType shapeType;
    Vector2D size; // For AABBs, this represents half extents
    float radius; // For circles

    RigidBody2D(float mass, const Vector2D& position, ShapeType shapeType, const Vector2D& size);

    // Update the rigid body's position and velocity based on forces and time
    void update(float deltaTime);

    // Apply force at a specific point (relative to the center of mass)
    void applyForce(const Vector2D& force, const Vector2D& pointOfApplication);

    // Apply torque
    void applyTorque(float torque);
};

#endif // DYNAVERSE2D_H