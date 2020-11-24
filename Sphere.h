#pragma once
#include "constants.h"
#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"
#include "Shape.h"

class Sphere :
    public Shape
{
public:
    real r;
    Vector3d pos;

    const real intersect(const Ray& ray) const;
};

