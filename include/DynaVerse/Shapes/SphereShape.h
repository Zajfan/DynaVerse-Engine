#ifndef SPHERE_SHAPE_H
#define SPHERE_SHAPE_H

#include "DynaVerse/Physics/Shapes/Shape.h"

namespace DynaVerse {

    class SphereShape : public Shape {
    public:
        SphereShape(float radius);

        float getRadius() const;

    private:
        float radius;
    };

} // namespace DynaVerse

#endif // SPHERE_SHAPE_H