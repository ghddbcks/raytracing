#pragma once
#include "constants.h"
#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"

class Shape
{
public:
	Color color;

	virtual const real intersect(const Ray& ray) const = 0;
};

