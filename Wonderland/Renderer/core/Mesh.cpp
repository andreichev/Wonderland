//
//  Mesh.cpp
//  Neverland
//
//  Created by Admin on 13.07.2021.
//

#include <OpenGLES/ES3/gl.h>
#include <iostream>

#include "Mesh.hpp"

Mesh::Mesh(Vertex *vertices, unsigned int verticesCount, unsigned int *indices, unsigned int indicesCount, std::vector<Texture *> textures)
    : ib(indices, indicesCount)
    , vb(vertices, sizeof(Vertex) * verticesCount)
    , textures(textures) {
    VertexBufferLayout layout;
    layout.pushVector();
    va.addBuffer(vb, layout);
}

Mesh::~Mesh() {}

void Mesh::draw() {
    for (int i = 0; i < textures.size(); i++) {
        auto &texture = textures[i];
        texture->bind(i);
    }
    va.bind();
    ib.bind();
    glDrawElements(GL_TRIANGLES, ib.getSize(), GL_UNSIGNED_INT, 0);
}
