#ifndef DIRECTIONALLIGHT_H_
#define DIRECTIONALLIGHT_H_

#include "Light.h"

namespace Raytracer {
    class DirectionalLight : public Light {
    public:
        DirectionalLight();
        DirectionalLight(std::istringstream& iss);
        virtual ~DirectionalLight() {}

        virtual Vector3 getDirection(const ShadeInfo& shadeInfo) const;
        virtual Colour getRadiance(const ShadeInfo& shadeInfo) const;

        void setDirection(const Vector3& direction);

        virtual bool inShadow(const ShadeInfo& shadeInfo, const World& world) const;

    private:
        Vector3 direction;
    };
}

#endif /* DIRECTIONALLIGHT_H_ */
