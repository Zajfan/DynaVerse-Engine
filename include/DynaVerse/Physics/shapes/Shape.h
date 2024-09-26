#ifndef SHAPE_H
#define SHAPE_H

namespace DynaVerse {

    // Base Shape class (abstract)
    class Shape {
    public:
        virtual ~Shape() = default; // Virtual destructor for proper cleanup of derived classes

        // Pure virtual functions to be implemented by derived shapes
        virtual void getAABB(const RigidBody2D& body, AABB& outAABB) const = 0;
        // ... other potential virtual functions for collision detection, etc.
    };

} // namespace DynaVerse

#endif // SHAPE_H