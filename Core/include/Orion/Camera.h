#pragma once
#include <glm/glm.hpp>
#include "Orion/Event.h"

namespace Orion {
    struct CameraAttribs {
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;

        float cameraSpeed;
    };
    extern CameraAttribs mainCamSettings;

}