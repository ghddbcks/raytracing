#include "Sphere.h"
#include "constants.h"
#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"
#include "Shape.h"
#include <math.h>
#include <algorithm>

namespace raytracing {
	const real Sphere::intersect(const Ray& ray) const
	{
		real B = 2 * (ray.direction.x * (ray.origin.x - pos.x) + ray.direction.y * (ray.origin.y - pos.y) + ray.direction.z * (ray.origin.z - pos.z));
		real C = (ray.origin - pos).sqrnorm();

		real d = B * B - 4 * C;

		if (d < 0) {
			return NAN;
		}
		else {
			real t1 = (-B + sqrt(d)) / 2;
			real t2 = (-B - sqrt(d)) / 2;

			if (d == 0) {
				return t1;
			}
			else if (d > 0) {
				return std::min(t1, t2);
			}
		}
	}
}
