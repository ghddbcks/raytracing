#pragma once
#include "Ray.h"
#include "Vector3d.h"
#include "constants.h"
#include "Shape.h"
#include "LightSource.h"
#include "Color.h"
#include <vector>

using namespace std;

namespace raytracing {
	class Camera
	{
	private:
		Vector3d position;
		Vector3d direction;
		int pixwidth;
		int pixheight;
		real pixsize;
		real sensordistance;

	public:
		Camera(Vector3d position, Vector3d direction, int pixwidth, int pixheight, real pixsize, real sensordistance) : position(position), direction(direction), pixheight(pixheight), pixwidth(pixwidth), pixsize(pixsize), sensordistance(sensordistance) {}

		const Color shootray(const int& i, const int& j, const vector<Shape>& objects, const vector<LightSource>& lightsources, const Color& defaultcolor) const;
		const vector<vector<Color>> render(const vector<Shape>& objects, const vector<LightSource>& lightsources) const;
		const Ray calc_ray_dir(const int& i, const int& j) const;

		const std::pair<real, Shape> minimal_distance(const vector<Shape>& objects, const Ray& ray) const;

		void moveposition(const Vector3d& newposition);
		void rotate(const Vector3d& newrotation);
	};
}
