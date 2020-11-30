#pragma once
#include "constants.h"
#include "Vector3d.h"

namespace raytracing {
	class Color
	{
	public:
		unsigned char R;
		unsigned char G;
		unsigned char B;

		Color(char R, char G, char B) : R(R), G(G), B(B) {}
		Color(Vector3d vector) : R(vector.x), G(vector.y), B(vector.z) {}
		Color() : R(0), G(0), B(0) {}
	};
}
