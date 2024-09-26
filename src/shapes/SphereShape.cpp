#include "DynaVerse/Physics/Shapes/SphereShape.h"

namespace DynaVerse {

    SphereShape::SphereShape(float radius) : radius(radius) {}

    float SphereShape::getRadius() const {
        return radius;
    }

} // namespace DynaVerse