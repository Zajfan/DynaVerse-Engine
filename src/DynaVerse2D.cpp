#include "DynaVerse2D.h"
#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse/CollisionDetection2D.h"
#include "DynaVerse/CollisionResponse2D.h"
#include "DynaVerse/Utils2D.h" 
#include <cmath>

// 2D Rigid Body Class Implementation

RigidBody2D::RigidBody2D(float mass, const Vector2D& position, ShapeType shapeType, const Vector2D& size)
    : mass(mass), momentOfInertia(0), position(position),
    angle(0), linearVelocity(0, 0), angularVelocity(0),
    shapeType(shapeType), size(size), radius(0)
{
    if (shapeType == CIRCLE) {
        radius = size.x; // Assume circles are defined by their radius
    }
}

void RigidBody2D::update(float deltaTime) {
    // Apply gravity (you can customize this later)
    Vector2D gravity(0, -9.81f);
    linearVelocity = linearVelocity + (gravity * deltaTime);

    // Update position based on velocity
    position = position + (linearVelocity * deltaTime);

    // Update angle based on angular velocity
    angle += angularVelocity * deltaTime;

    // Collision Detection & Response (assuming a global array 'rigidBodies' exists)
    for (int i = 0; i < numRigidBodies; i++) {
        if (&rigidBodies[i] == this) continue; // Skip self-collision

        RigidBody2D& otherBody = rigidBodies[i];

        // Get AABBs
        AABB aabb1 = getAABBForBody(*this);
        AABB aabb2 = getAABBForBody(otherBody);

        if (checkAABBCollision(aabb1, aabb2)) {
            resolveAABBCollision(*this, aabb1, otherBody, aabb2);
        }
    }
}

void RigidBody2D::applyForce(const Vector2D& force, const Vector2D& pointOfApplication) {
    linearVelocity = linearVelocity + (force / mass);
    angularVelocity += (pointOfApplication - position).cross(force) / momentOfInertia;
}

void RigidBody2D::applyTorque(float torque) {
    angularVelocity += torque / momentOfInertia;
}

// Basic Collision Detection (Circle-Circle)
bool checkCircleCircleCollision(const RigidBody2D& body1, float radius1,
    const RigidBody2D& body2, float radius2) {
    float distanceSquared = (body1.position - body2.position).squaredMagnitude();
    float combinedRadiiSquared = (radius1 + radius2) * (radius1 + radius2);
    return distanceSquared <= combinedRadiiSquared;
}