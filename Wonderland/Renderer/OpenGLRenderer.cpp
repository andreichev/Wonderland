//
//  OpenGLRenderer.cpp
//  Wonderland
//
//  Created by Admin on 02.08.2021.
//

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "OpenGLRenderer.hpp"

OpenGLRenderer::OpenGLRenderer(std::string rootPath)
    : base((rootPath + "/Vertex.glsl").c_str(), (rootPath + "/Fragment.glsl").c_str())
    , grass1((rootPath + "/arbuz.png").c_str())
    , clearColor(0.07f, 0.13f, 0.17f, 1.0f)
    , translate(0.f, 0.f, 13.f) {
    glEnable(GL_DEPTH_TEST);

    std::vector<Texture *> textures;
    textures.push_back(&grass1);

    const float SIZE = 8.f;
    Vertex vertices[] = {
        // Front
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 0
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 1
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 2
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(0.0f, 0.0f)),  // 3
        // Back
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 4
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 5
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 6
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 0.0f)),  // 7
        // Top
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 8
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 11
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 10
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 0.0f)),  // 9
        // Bottom
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 12
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 13
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 14
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(0.0f, 0.0f)),  // 15
        // Left
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 16
        Vertex(glm::vec3(-SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 17
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 18
        Vertex(glm::vec3(-SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 0.0f)),  // 19
        // Right
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(0.0f, 1.0f)), // 20
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, -SIZE / 2.0f), glm::vec2(1.0f, 1.0f)),  // 23
        Vertex(glm::vec3(SIZE / 2.0f, SIZE / 2.0f, SIZE / 2.0f), glm::vec2(1.0f, 0.0f)),   // 22
        Vertex(glm::vec3(SIZE / 2.0f, -SIZE / 2.0f, SIZE / 2.0f), glm::vec2(0.0f, 0.0f))   // 21
    };

    unsigned int indices[36] = {
        0, 1, 2, 2, 3, 0,       // Front
        4, 5, 6, 6, 7, 4,       // Back
        8, 9, 10, 10, 11, 8,    // Top
        12, 13, 14, 14, 15, 12, // Bottom
        16, 17, 18, 18, 19, 16, // Left
        20, 21, 22, 22, 23, 20  // Right
    };

    mesh = new Mesh(vertices, 24, indices, 36, textures);

    view = glm::rotate(glm::mat4(1.0f), glm::radians(180.f), glm::vec3(0.0f, 1.0f, 0.0f));
    projectionMatrix = glm::perspective(90.f, 1.0f, 0.1f, 1000.0f);
    model = glm::mat4(1.0f);

    base.use();
    base.setMat4("projection", projectionMatrix);
}

OpenGLRenderer::~OpenGLRenderer() {
    delete mesh;
}

void OpenGLRenderer::render(float time) {
    glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    base.use();
    base.setInt("texture1", 0);
    model = glm::mat4(1.f);
    model = glm::scale(glm::mat4(1.f), glm::vec3(abs(sin(time)) + 1.f, abs(sin(time)) + 1.f, 1.f));
    model = glm::translate(model, translate);
    model = glm::rotate(model, time, glm::vec3(1.f, 1.f, 0.f));
    base.setMat4("view", view);
    base.setMat4("model", model);

    mesh->draw();
}

void OpenGLRenderer::updateScreenSize(float width, float height) {
    glViewport(0, 0, width, height);
    projectionMatrix = glm::perspective(90.f, width / height, 0.1f, 1000.0f);
    base.setMat4("projection", projectionMatrix);
}
