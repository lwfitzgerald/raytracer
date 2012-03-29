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

class Object;
class Point3;
class Vector3;
class Normal;
class Matrix;
class Colour;
class BoundingBox;

class Ray;
class ShadeInfo;

class World;
class ViewPlane;
class Camera;
class RegularCamera;

class Material;
class Lambert;

class Light;
class AmbientLight;

#endif /* PREREQS_H_ */
