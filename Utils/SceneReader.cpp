#include "SceneReader.h"
#include "../Objects/Sphere.h"
#include "../Objects/Plane.h"
#include "../Objects/Disc.h"
#include "../Objects/Triangle.h"
#include "../Cameras/RegularCamera.h"
#include "../Lights/AmbientLight.h"
#include "../Lights/PointLight.h"
#include "../Lights/SpotLight.h"
#include "../Lights/DirectionalLight.h"
#include "../Materials/Matte.h"
#include "../Materials/Specular.h"
#include "../Materials/Transparent.h"

namespace Raytracer {
    void SceneReader::buildScene(const char* filePath, World& world) {
        std::cout << "Building scene..." << std::endl;
        clock_t start = clock();

        std::ifstream file(filePath);

        // Check if file handle is valid
        if (!file.good()) {
            std::cerr << "Could not read scene input file" << std::endl;
            std::exit(1);
        }

        unsigned int lineNo = 1;
        std::string line;
        std::string mainName;

        while (!file.eof()) {
            // Read a line from the input file
            std::getline(file, line);

            // Convert to uppercase
            uppercaseString(line);

            // Set up the istringstream for parsing
            std::istringstream iss(line);

            if (line.empty() || containsOnlyWhitespace(line)) {
                // Empty line so continue
                lineNo++;
                continue;
            }

            // Get the main name
            iss >> mainName;

            if (mainName.substr(0, 1).compare("#") == 0) {
                // This line contains a comment so continue
                lineNo++;
                continue;
            }

            if (mainName.compare("VIEWPLANE") == 0) {
                handleViewPlane(iss, world);
            } else if (mainName.compare("AMBIENTLIGHT") == 0) {
                handleAmbientLight(iss, world);
            } else if (mainName.compare("POINTLIGHT") == 0) {
                handlePointLight(iss, world);
            } else if (mainName.compare("SPOTLIGHT") == 0) {
                handleSpotLight(iss, world);
            } else if (mainName.compare("DIRECTIONALLIGHT") == 0) {
                handleDirectionalLight(iss, world);
            } else if (mainName.compare("MATTE") == 0) {
                handleMatte(iss, world);
            } else if (mainName.compare("SPECULAR") == 0) {
                handleSpecular(iss, world);
            } else if (mainName.compare("TRANSPARENT") == 0) {
                handleTransparent(iss, world);
            } else if (mainName.compare("CAMERA") == 0) {
                handleCamera(iss, world);
            } else if (mainName.compare("SPHERE") == 0) {
                handleSphere(iss, world);
            } else if (mainName.compare("PLANE") == 0) {
                handlePlane(iss, world);
            } else if (mainName.compare("DISC") == 0) {
                handleDisc(iss, world);
            } else if (mainName.compare("TRIANGLE") == 0) {
                handleTriangle(iss, world);
            } else {
                handleWarning(lineNo);
            }

            if (iss.fail()) {
                handleError(lineNo);
            }

            lineNo++;
        }

        clock_t end = clock();
        double time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
        std::cout << "Scene built in " << time << "ms" << std::endl;
    }

    void SceneReader::handleViewPlane(std::istringstream& iss, World& world) {
        unsigned int hres, vres;

        iss >> hres;
        iss >> vres;

        float pixelSize;

        iss >> pixelSize;

        world.setViewPlaneResolution(hres, vres);
        world.setViewPlanePixelSize(pixelSize);
    }

    void SceneReader::handleCamera(std::istringstream& iss, World& world) {
        RegularCamera* camera = new RegularCamera(iss);
        world.setCamera(camera);
    }

    void SceneReader::handleAmbientLight(std::istringstream& iss, World& world) {
        AmbientLight* ambientLight = new AmbientLight(iss);
        world.setAmbientLight(ambientLight);
    }

    void SceneReader::handlePointLight(std::istringstream& iss, World& world) {
        PointLight* pointLight = new PointLight(iss);
        world.addLight(pointLight);
    }

    void SceneReader::handleSpotLight(std::istringstream& iss, World& world) {
        SpotLight* spotLight = new SpotLight(iss);
        world.addLight(spotLight);
    }

    void SceneReader::handleDirectionalLight(std::istringstream& iss, World& world) {
        DirectionalLight* directionalLight = new DirectionalLight(iss);
        world.addLight(directionalLight);
    }

    void SceneReader::handleMatte(std::istringstream& iss, World& world) {
        Matte* lambert = new Matte(iss);

        // Store in world vector (used for delete'ing at end)
        world.addMaterial(lambert);

        // Store in hash map for lookup during scene build
        world.materials[lambert->name] = lambert;
    }

    void SceneReader::handleSpecular(std::istringstream& iss, World& world) {
        Specular* phong = new Specular(iss);

        // Store in world vector (used for delete'ing at end)
        world.addMaterial(phong);

        // Store in hash map for lookup during scene build
        world.materials[phong->name] = phong;
    }

    void SceneReader::handleTransparent(std::istringstream& iss, World& world) {
        Transparent* transparent = new Transparent(iss);

        // Store in world vector (used for delete'ing at end)
        world.addMaterial(transparent);

        // Store in hash map for lookup during scene build
        world.materials[transparent->name] = transparent;
    }

    void SceneReader::handleSphere(std::istringstream& iss, World& world) {
        Sphere* sphere = new Sphere(iss, world);
        world.addObject(sphere);
    }

    void SceneReader::handlePlane(std::istringstream& iss, World& world) {
        Plane* plane = new Plane(iss, world);
        world.addObject(plane);
    }

    void SceneReader::handleDisc(std::istringstream& iss, World& world) {
        Disc* disc = new Disc(iss, world);
        world.addObject(disc);
    }

    void SceneReader::handleTriangle(std::istringstream& iss, World& world) {
        Triangle* triangle = new Triangle(iss, world);
        world.addObject(triangle);
    }

    void SceneReader::uppercaseString(std::string& string) {
        std::string::iterator itr;

        for (itr = string.begin(); itr != string.end(); itr++) {
            *itr = toupper(*itr);
        }
    }

    bool SceneReader::containsOnlyWhitespace(const std::string& string) {
        std::string::const_iterator itr;

        for (itr = string.begin(); itr != string.end(); itr++) {
            if (*itr != '\n' && *itr != ' ' && *itr != '\t') {
                return false;
            }
        }

        return true;
    }

    void SceneReader::handleError(unsigned int lineNo) {
        std::cerr << "Error parsing input file on line " << lineNo << std::endl;
        std::exit(1);
    }

    void SceneReader::handleWarning(unsigned int lineNo) {
        std::cout << "Warning: Unrecognised input data on line " << lineNo << std::endl;
    }
}
