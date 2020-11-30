#pragma once
#include "constants.h"
#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"

namespace raytracing {
	class Shape
	{
	public:
		Color color;

		virtual const real intersect(const Ray& ray) const { return 0; };
	};
}
