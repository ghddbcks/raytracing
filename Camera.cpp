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

    const pair<Shape, real> Camera::nearest(const Ray& ray, const vector<Shape>& shapes) const
    {
        real min_t = INFINITY;
        Shape nearest_shape = Shape();
        real t;
        for (Shape s : shapes) {
            t = s.intersect(ray);
            if (min_t > t) {
                min_t = t;
                nearest_shape = s;
            }
        }
        return pair<Shape, real>(nearest_shape, min_t);
    }

    const Color Camera::trace_ray(const Ray& ray, const vector<Shape>& shapes, const vector<LightSource> lights, const Color& default_color) const
    {
        auto nearest_shape = nearest(ray, shapes);

        if (nearest_shape.second != INFINITY) {
            bool shadow = is_shadow(ray, nearest_shape.second, lights, shapes);
            return shadow ? Color(0, 0, 0) : nearest_shape.first.color;
        }
        else {
            return default_color;
        }
    }

    const bool Camera::is_shadow(const Ray& ray, const real& t, const vector<LightSource> lights, const vector<Shape> shapes) const
    {
        bool shadow = true;
        Vector3d origin = ray.origin + ray.direction * t;
        for (LightSource l : lights) {
            Ray shadow_ray = Ray(origin, (l.pos - origin).normalization());
            auto nearest_object = nearest(shadow_ray, shapes);
            if (nearest_object.second == INFINITY || (l.pos - origin).norm() < nearest_object.second || nearest_object.second <= 0.0f){
                shadow = false;
            }
        }
        return shadow;
    }

    const vector<vector<Color>> Camera::render(const vector<Shape>& objects, const vector<LightSource>& lightsources) const
    {
        vector<vector<Color>> result(pixwidth, vector<Color>(pixwidth, Color(0, 0, 0)));
        for (int i = 0; i < pixwidth; i++) {
            for (int j = 0; j < pixheight; j++) {
                result[i][j] = trace_ray(calc_ray_dir(i, j), objects, lightsources, Color(255, 255, 0));
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
}
