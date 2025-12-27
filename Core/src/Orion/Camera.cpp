#include "Orion/Camera.h"
#include "Orion/Renderer.h"

namespace Orion {
    CameraAttribs mainCamSettings = {
        glm::vec3(0.0f, 0.0f, 3.0f),  // cameraPos
        glm::vec3(0.0f, 0.0f, -1.0f), // cameraFront
        glm::vec3(0.0f, 1.0f, 0.0f),  // cameraUp
        16.0f                         // cameraSpeed
    };


}