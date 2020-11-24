#pragma once
#include "constants.h"
#include "Vector3d.h"

class Color : public Vector3d
{
public:
	real x;
	real y;
	real z;

	Color(real x, real y, real z) : x(x), y(y), z(z) {}
	Color(Vector3d vector) : x(vector.x), y(vector.y), z(vector.z) {}
	Color() : x(0), y(0), z(0) {}
	const Color calculate_reflection(const Color& lightcolor, const Color& objectcolor) const;
};

