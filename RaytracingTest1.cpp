#include <iostream>
#include "RaytracingTest1.h"
#include <math.h>
#include <algorithm>
#include "vector3d.h"
#include "constants.h"
#include "Shape.h"
#include "Sphere.h"
#include "Camera.h"
#include "LightSource.h"
#include "Color.h"
#include "Ray.h"
#include <vector>

using namespace raytracing;
using namespace std;
int main()
{
    vector<LightSource> lights { LightSource(Vector3d(0, -10, 0), 5) };
    vector<Shape> shapes { Sphere(Vector3d(0, 5, 0), Color(0, 255, 0), 1) };
    Camera camera = Camera(Vector3d(0, 0, 0), Vector3d(0, 1, 0), 10, 10, 1, 1);

    auto result = camera.render(shapes, lights);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << (int)result[i][j].R << " " << (int)result[i][j].G << " " << (int)result[i][j].B << endl;
        }
    }
}
