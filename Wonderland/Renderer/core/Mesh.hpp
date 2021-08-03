//
//  Mesh.hpp
//  Neverland
//
//  Created by Admin on 13.07.2021.
//

#pragma once
#include <glm/glm.hpp>
#include <string>

#include "IndexBuffer.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"

class Mesh {
    VertexArray va;
    IndexBuffer ib;
    VertexBuffer vb;
    std::vector<Texture *> textures;

public:
    Mesh(Vertex *vertices, unsigned int verticesCount, unsigned int *indices, unsigned int indicesCount, std::vector<Texture *> texutres);
    ~Mesh();
    void draw();
};
