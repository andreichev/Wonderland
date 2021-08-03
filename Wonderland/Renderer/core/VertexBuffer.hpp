//
//  VertexBuffer.hpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#pragma once

class VertexBuffer {
private:
    unsigned int m_RendererID;

public:
    VertexBuffer(const void *data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;
};
