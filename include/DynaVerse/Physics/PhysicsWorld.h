#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <vector>
#include "DynaVerse/Physics/RigidBody.h" 

namespace DynaVerse {

    class PhysicsWorld {
    public:
        PhysicsWorld();
        ~PhysicsWorld();

        void addRigidBody(RigidBody* body);
        void removeRigidBody(RigidBody* body);

        void stepSimulation(float deltaTime);

    private:
        std::vector<RigidBody*> rigidBodies;

        // Other potential private members (e.g., gravity, collision detection/response systems, etc.)
    };

} // namespace DynaVerse

#endif // PHYSICS_WORLD_H