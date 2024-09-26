#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "DynaVerse/math/Vector3D.h"
#include "DynaVerse/Physics/Shapes/Shape.h" // Forward declare a base Shape class

namespace DynaVerse {

    class RigidBody {
    public:
        RigidBody(float mass, const Vector3D& position, Shape* shape);
        ~RigidBody();

        void applyForce(const Vector3D& force);
        void applyImpulse(const Vector3D& impulse, const Vector3D& contactPoint);

        void update(float deltaTime);

        // Accessors and other methods as needed
        float getMass() const;
        Vector3D getPosition() const;
        Vector3D getVelocity() const;
        // ...

    private:
        float mass;
        Vector3D position;
        Vector3D linearVelocity;
        // ... (other properties like inertia, angular velocity, orientation, etc. for 3D)

        Shape* shape;
    };

} // namespace DynaVerse

#endif // RIGID_BODY_H