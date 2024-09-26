#include "DynaVerse3D.h"
#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse/math/Vector3D.h"
#include <cmath>

// 3D Vector Class Implementation
Vector3D::Vector3D() : x(0), y(0), z(0) {}
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

// ... (Implement 3D vector operations: +, -, *, /, dot, cross, magnitude, normalize)

// 3D Rigid Body Class Implementation
RigidBody3D::RigidBody3D(float mass, const Vector3D& position)
    : mass(mass),
    inertiaTensor(Matrix3x3()), // Initialize to identity matrix for now
    position(position),
    orientation(Quaternion()), // Initialize to no rotation
    linearVelocity(0, 0, 0),
    angularVelocity(0, 0, 0) {}

void RigidBody3D::update(float deltaTime) {
    // Apply gravity (you can customize this later)
    Vector3D gravity(0, -9.81f, 0); // Use 'f' suffix for float literals
    linearVelocity = linearVelocity + (gravity * deltaTime);

    // Update position based on velocity
    position = position + (linearVelocity * deltaTime);

    // Update orientation based on angular velocity (we'll implement this later)
    // ...
}

// ... (Implement other 3D rigid body methods as needed)