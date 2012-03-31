#include "SceneReader.h"
#include "../Objects/Sphere.h"
#include "../Objects/Plane.h"
#include "../Objects/Disc.h"
#include "../Objects/Triangle.h"
#include "../Cameras/RegularCamera.h"
#include "../Lights/AmbientLight.h"
#include "../Lights/PointLight.h"
#include "../Lights/DirectionalLight.h"
#include "../Materials/Lambert.h"
#include "../Materials/Phong.h"

void SceneReader::buildScene(const char* filePath, World& world) {
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
        } else if (mainName.compare("DIRECTIONALLIGHT") == 0) {
            handleDirectionalLight(iss, world);
        } else if (mainName.compare("LAMBERT") == 0) {
            handleLambert(iss, world);
        } else if (mainName.compare("PHONG") == 0) {
            handlePhong(iss, world);
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
    double eyeX, eyeY, eyeZ;

    iss >> eyeX;
    iss >> eyeY;
    iss >> eyeZ;

    double lookAtX, lookAtY, lookAtZ;

    iss >> lookAtX;
    iss >> lookAtY;
    iss >> lookAtZ;

    double viewPlaneDistance;

    iss >> viewPlaneDistance;

    double rollAngle;

    iss >> rollAngle;

    RegularCamera* camera = new RegularCamera();
    camera->setEyePoint(Point3(eyeX, eyeY, eyeZ));
    camera->setLookAtPoint(Point3(lookAtX, lookAtY, lookAtZ));
    camera->setViewPlaneDistance(viewPlaneDistance);
    camera->calcUVW();
    camera->setRollAngle(rollAngle);
    camera->calcUVW();

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

void SceneReader::handleDirectionalLight(std::istringstream& iss, World& world) {
    double r, g, b;

    iss >> r;
    iss >> g;
    iss >> b;

    double x, y, z;

    iss >> x;
    iss >> y;
    iss >> z;

    DirectionalLight* directionalLight = new DirectionalLight();
    directionalLight->setColour(Colour(r, g, b));
    directionalLight->setDirection(Vector3(x, y, z));

    world.addLight(directionalLight);
}

void SceneReader::handleLambert(std::istringstream& iss, World& world) {
    Lambert* lambert = new Lambert(iss);

    // Store in world vector (used for delete'ing at end)
    world.addMaterial(lambert);

    // Store in hash map for lookup during scene build
    world.materials[lambert->name] = lambert;
}

void SceneReader::handlePhong(std::istringstream& iss, World& world) {
    Phong* phong = new Phong(iss);

    // Store in world vector (used for delete'ing at end)
    world.addMaterial(phong);

    // Store in hash map for lookup during scene build
    world.materials[phong->name] = phong;
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
