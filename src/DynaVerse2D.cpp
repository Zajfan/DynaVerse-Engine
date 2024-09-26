#include "DynaVerse2D.h"
#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse/CollisionDetection2D.h"
#include <cmath>

// 2D Rigid Body Class Implementation

RigidBody2D::RigidBody2D(float mass, const Vector2D& position)
    : mass(mass), momentOfInertia(0), position(position),
    angle(0), linearVelocity(0, 0), angularVelocity(0) {}

void RigidBody2D::update(float deltaTime) {
    // Apply gravity (you can customize this later)
    Vector2D gravity(0, -9.81f); // Use 'f' suffix for float literals
    linearVelocity = linearVelocity + (gravity * deltaTime);

    // Update position based on velocity
    position = position + (linearVelocity * deltaTime);

    // Update angle based on angular velocity
    angle += angularVelocity * deltaTime;

    // Placeholder for collision detection and response
    // (We'll implement this in more detail later)
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

// Basic Collision Response (Circle-Circle)
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