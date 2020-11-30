#pragma once
#include "Ray.h"
#include "Vector3d.h"
#include "constants.h"
#include "Shape.h"
#include "LightSource.h"
#include "Color.h"
#include <vector>
#include <utility>

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

		const vector<vector<Color>> render(const vector<Shape>& objects, const vector<LightSource>& lightsources) const;
		const Ray calc_ray_dir(const int& i, const int& j) const;

		void moveposition(const Vector3d& newposition);
		void rotate(const Vector3d& newrotation);

		const pair<Shape, real> nearest(const Ray& ray, const vector<Shape>& shapes) const;
		const Color trace_ray(const Ray& ray, const vector<Shape>& shapes, const vector<LightSource> lights, const Color& default_color) const;
		const bool is_shadow(const Ray& ray, const real& t, const vector<LightSource> lights, const vector<Shape> shapes) const;
	};
}
