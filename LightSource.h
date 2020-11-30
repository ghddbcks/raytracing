#pragma once
#include "constants.h"
#include "Vector3d.h"
#include "Color.h"

namespace raytracing {
	class LightSource
	{
	public:
		Vector3d pos;
		real intencity;

		LightSource(Vector3d pos, real intencity) : pos(pos), intencity(intencity) {};
	};
}
