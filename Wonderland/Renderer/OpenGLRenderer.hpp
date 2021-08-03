//
//  OpenGLRenderer.hpp
//  Wonderland
//
//  Created by Admin on 02.08.2021.
//

#pragma once

#include <glm/glm.hpp>

#include "core/Shader.hpp"
#include "core/Texture.hpp"
#include "core/Mesh.hpp"

class OpenGLRenderer {
private:
    Shader base;
    Texture grass1;
    Mesh *mesh;

    glm::mat4 view;
    glm::mat4 projectionMatrix;
    glm::mat4 model;
    glm::vec4 clearColor;
    glm::vec3 translate;

public:
    OpenGLRenderer(std::string rootPath);
    ~OpenGLRenderer();

    void render(float time);
    void updateScreenSize(float width, float height);
};
