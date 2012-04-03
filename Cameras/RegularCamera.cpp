#include "RegularCamera.h"

#include "../Utils/Ray.h"
#include "../Utils/ShadeInfo.h"
#include "../World.h"
#include "../ViewPlane.h"

namespace Raytracer {
    void RegularCamera::renderPixel(unsigned int arrayX, unsigned int arrayY, World& world) const {
        ViewPlane& viewPlane = world.viewPlane;

        Ray ray;
        ShadeInfo shadeInfo;
        double x, y;

        ray.origin = eye;

        x = viewPlane.pixelSize * (arrayX - 0.5 * viewPlane.horizontalRes + 0.5);
        y = viewPlane.pixelSize * (0.5 * viewPlane.verticalRes - arrayY - 0.5);

        ray.direction = x * this->u + y * this->v - this->viewPlaneDistance * this->w;
        ray.direction.normalise();

        // Intersect with all objects in scene
        shadeInfo = world.hitObjects(ray);

        if (shadeInfo.hit) {
            viewPlane.setPixelColour(arrayX, arrayY, shadeInfo.colour);
        } else {
            viewPlane.setPixelColour(arrayX, arrayY, world.backgroundColour);
        }
    }

    void RegularCamera::setViewPlaneDistance(const double& distance) {
        this->viewPlaneDistance = distance;
    }
}
