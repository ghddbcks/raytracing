#pragma once
#include "constants.h"
#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"
#include "Shape.h"

namespace raytracing {
    class Sphere :
        public Shape
    {
    public:
        real r;
        Vector3d pos;
        Color color;

        Sphere(Vector3d pos, Color color, real r) : pos(pos), color(color), r(r) {};
        const real intersect(const Ray& ray) const override;
    };
}
