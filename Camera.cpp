#include "Camera.h"
#include <vector>
#include <algorithm>
#include <utility>

namespace raytracing {
    void Camera::moveposition(const Vector3d& newposition)
    {
        position = newposition;
    }

    void Camera::rotate(const Vector3d& newrotation)
    {
        direction = newrotation;
    }

    const Color Camera::shootray(const int& i, const int& j, const vector<Shape>& objects, const vector<LightSource>& lightsources, const Color& defaultcolor) const
    {
        Ray ray = calc_ray_dir(i, j);
        real result = 0;

        auto min_dist = minimal_distance(objects, ray);

        if (min_dist.first == INFINITY) {
            return defaultcolor;
        }

        Vector3d neworigin = ray.origin + ray.direction * min_dist.first;

        bool is_shadow = true;
        for (const auto& lightsource : lightsources) {
            Ray ray = Ray(neworigin, (lightsource.pos - ray.origin).normalization());
            real dist = (lightsource.pos - ray.origin).norm();

            min_dist = minimal_distance(objects, ray);
            is_shadow &= min_dist.first > dist;
        }
        return is_shadow ? Color(0, 0, 0) : min_dist.second.color;
    }

    const vector<vector<Color>> Camera::render(const vector<Shape>& objects, const vector<LightSource>& lightsources) const
    {
        vector<vector<Color>> result(pixwidth, vector<Color>(pixwidth, Color(0, 0, 0)));
        for (int i = 0; i < pixwidth; i++) {
            for (int j = 0; j < pixheight; j++) {
                result[i][j] = shootray(i, j, objects, lightsources, Color(0, 0, 0));
            }
        }
        return result;
    }

    const Ray Camera::calc_ray_dir(const int& i, const int& j) const
    {
        real x = (i - float(i)) * pixsize;
        real y = (j - float(j)) * pixsize;

        return Ray(position, Vector3d(x, y, sensordistance).normalization());
    }

    const std::pair<real, Shape> Camera::minimal_distance(const vector<Shape>& objects, const Ray& ray) const
    {
        real min_dist = INFINITY;
        Shape nearest;
        for (const auto& object : objects) {
            real dist = object.intersect(ray);
            if (dist < min_dist) {
                min_dist = dist;
                nearest = object;
            }
        }
        return std::pair<real, Shape>(min_dist, nearest);
    }
}
