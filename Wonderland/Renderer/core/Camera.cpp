//
//  Camera.cpp
//  Neverland
//
//  Created by Admin on 21.07.2021.
//

#include "Camera.hpp"

glm::mat4 Camera::getViewMatrix() {
    glm::mat4 view = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::translate(view, position);
    return view;
}
