#include "../../DynaVerse/Physics/PhysicsWorld.h" 

namespace DynaVerse {

    PhysicsWorld::PhysicsWorld() {
        // Initialize any necessary data structures or systems here
    }

    PhysicsWorld::~PhysicsWorld() {
        // Clean up any allocated resources here (e.g., delete rigid bodies)
    }

    void PhysicsWorld::addRigidBody(RigidBody* body) {
        rigidBodies.push_back(body);
    }

    void PhysicsWorld::removeRigidBody(RigidBody* body) {
        // Find and remove the body from the rigidBodies vector
        // ...
    }

    void PhysicsWorld::stepSimulation(float deltaTime) {
        // 1. Integrate rigid body motion
        for (RigidBody* body : rigidBodies) {
            body->update(deltaTime);
        }

        // 2. Perform collision detection and response
        // ... (You'll implement this later)
    }

} // namespace DynaVerse