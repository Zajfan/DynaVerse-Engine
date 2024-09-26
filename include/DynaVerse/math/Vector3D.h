#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

class Vector3D {
public:
    float x, y, z;

    Vector3D();
    Vector3D(float x, float y, float z);

    // Vector addition
    Vector3D operator+(const Vector3D& other) const;

    // Vector subtraction
    Vector3D operator-(const Vector3D& other) const;

    // Scalar multiplication
    Vector3D operator*(float scalar) const;

    // Scalar division
    Vector3D operator/(float scalar) const;

    // Dot product
    float dot(const Vector3D& other) const;

    // Cross product
    Vector3D cross(const Vector3D& other) const;

    // Magnitude (length)
    float magnitude() const;

    // Squared magnitude (avoids the square root for efficiency in some cases)
    float squaredMagnitude() const;

    // Distance to another vector
    float distanceTo(const Vector3D& other) const;

    // Normalize (make unit length)
    void normalize();
};

#endif // VECTOR3D_H