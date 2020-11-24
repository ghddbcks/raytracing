#include "Camera.h"
#include <vector>
#include <algorithm>

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
    
    real min_dist = minimal_distance(objects, ray);

    if (min_dist == INFINITY) {
        return defaultcolor;
    }

    Vector3d neworigin = ray.origin + ray.direction * min_dist;
    bool is_shadow = true;
    for (const auto& lightsource : lightsources) {
        Ray ray = Ray(neworigin, (lightsource.pos - ray.origin).normalization());
        real dist = (lightsource.pos - ray.origin).norm();

        real min_dist = minimal_distance(objects, ray);
        is_shadow &= min_dist > dist;
    }
    return is_shadow ? 
}

const vector<vector<Color>> Camera::render(const vector<Shape>& objects, const vector<LightSource>& lightsources) const
{
    return vector<vector<Color>>();
}

const Ray Camera::calc_ray_dir(const int& i, const int& j) const
{
    real x = (i - float(i)) * pixsize;
    real y = (j - float(j)) * pixsize;

    return Ray(position, Vector3d(x, y, sensordistance).normalization());
}

const real Camera::minimal_distance(const vector<Shape>& objects, const Ray& ray) const
{
    real min_dist = INFINITY;
    Shape nearest;
    for (const auto& object : objects) {
        real dist = object.intersect(ray);
        min_dist = (dist < min_dist) ? dist : min_dist;
    }
    return min_dist;
}
