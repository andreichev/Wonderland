//
//  Camera.hpp
//  Neverland
//
//  Created by Admin on 21.07.2021.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement { FORWARD, BACKWARD, LEFT, RIGHT };

class Camera {
    glm::vec3 position;
    glm::vec2 rotation;

public:
    Camera();
    glm::mat4 getViewMatrix();
};
