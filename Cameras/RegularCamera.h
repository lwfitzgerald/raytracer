#ifndef REGULARCAMERA_H_
#define REGULARCAMERA_H_

#include "Camera.h"

namespace Raytracer {
    class RegularCamera: public Camera {
    public:
        RegularCamera() {}
        virtual ~RegularCamera() {}

        virtual void renderScene(World& world) const;

        void setViewPlaneDistance(const double& distance);
    private:
        double viewPlaneDistance;
    };
}

#endif /* REGULARCAMERA_H_ */
