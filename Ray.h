#pragma once
#include "vector3d.h"
#define real float

class Ray
{
public:
	Vector3d origin;
	Vector3d direction;

	Ray(Vector3d origin, Vector3d direction) : origin(origin), direction(direction) {}
};

