#ifndef PREREQS_H_
#define PREREQS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <limits>
#include <map>

#include "Constants.h"

// Bit of a hack to ensure we can use a hash_map
namespace std {
    using namespace __gnu_cxx;
}

#define sqr(x) ((x) * (x))

namespace Raytracer {
    enum Axis {X_AXIS, Y_AXIS, Z_AXIS};

    class Object;
    class Point3;
    class Vector3;
    class Normal;
    class Matrix;
    class Colour;
    class BoundingBox;
    struct BVHNode;

    class Sphere;
    class Plane;
    class Disc;
    class Triangle;

    class Ray;
    class ShadeInfo;

    class World;
    class ViewPlane;
    class Camera;
    class RegularCamera;

    class Material;
    class Lambert;
    class Phong;

    class Light;
    class AmbientLight;
    class DirectionalLight;
    class PointLight;
}

#endif /* PREREQS_H_ */
