#ifndef DYNAVERSE3D_H
#define DYNAVERSE3D_H

#include <cmath>
#include "DynaVerse/math/Vector2D.h"
#include "DynaVerse/math/Vector3D.h"

// Forward declaration of Matrix3x3
class Matrix3x3;

// Forward declaration of Quaternion
class Quaternion;

// 3D Vector Class Declaration 
// (This is not needed here since we're including Vector3D.h)

// 3D Rigid Body Class Declaration
class RigidBody3D {
public:
    float mass;
    Matrix3x3 inertiaTensor;
    Vector3D position;
    Quaternion orientation;
    Vector3D linearVelocity;
    Vector3D angularVelocity;

    RigidBody3D(float mass, const Vector3D& position);

    // Update the rigid body's position and velocity based on forces and time
    void update(float deltaTime);

    // ... (Declare other 3D rigid body methods as needed)
};

#endif // DYNAVERSE3D_H