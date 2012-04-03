#ifndef SCENEREADER_H_
#define SCENEREADER_H_

#include "../Prereqs.h"
#include "../World.h"

namespace Raytracer {
    class SceneReader {
    public:
        /**
         * Build the scene from the given file
         */
        static void buildScene(const char* filePath, World& world);

    private:
        static void handleViewPlane(std::istringstream& iss, World& world);
        static void handleCamera(std::istringstream& iss, World& world);

        static void handleAmbientLight(std::istringstream& iss, World& world);
        static void handlePointLight(std::istringstream& iss, World& world);
        static void handleSpotLight(std::istringstream& iss, World& world);
        static void handleDirectionalLight(std::istringstream& iss, World& world);

        static void handleLambert(std::istringstream& iss, World& world);
        static void handlePhong(std::istringstream& iss, World& world);
        static void handleTransparent(std::istringstream& iss, World& world);

        static void handleSphere(std::istringstream& iss, World& world);
        static void handlePlane(std::istringstream& iss, World& world);
        static void handleDisc(std::istringstream& iss, World& world);
        static void handleTriangle(std::istringstream& iss, World& world);

        static void handleError(unsigned int lineNo);
        static void handleWarning(unsigned int lineNo);

        static void uppercaseString(std::string& string);
        static bool containsOnlyWhitespace(const std::string& string);
    };
}

#endif /* SCENEREADER_H_ */
