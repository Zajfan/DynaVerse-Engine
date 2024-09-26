#include "DynaVerse/Physics/RigidBody.h"

namespace DynaVerse {

    RigidBody::RigidBody(float mass, const Vector3D& position, Shape* shape)
        : mass(mass), position(position), linearVelocity(0, 0, 0),
        shape(shape)
    {
        // Initialize other properties (e.g., inertia, angular velocity, orientation) as needed
        // ...
    }

    RigidBody::~RigidBody() {
        // Delete the shape if you own it
        delete shape;
    }

    void RigidBody::applyForce(const Vector3D& force) {
        // Update linear velocity based on force and mass
        linearVelocity += force / mass;
    }

    void RigidBody::applyImpulse(const Vector3D& impulse, const Vector3D& contactPoint) {
        // Update linear and angular velocity based on impulse and contact point
        // ... (You'll implement this later)
    }

    void RigidBody::update(float deltaTime) {
        // Integrate position based on linear velocity
        position += linearVelocity * deltaTime;

        // Integrate orientation based on angular velocity (for 3D)
        // ... (You'll implement this later)
    }

    float RigidBody::getMass() const {
        return mass;
    }

    Vector3D RigidBody::getPosition() const {
        return position;
    }

    Vector3D RigidBody::getVelocity() const {
        return linearVelocity;
    }

    // ... (Implement other RigidBody methods as needed)

} // namespace DynaVerse