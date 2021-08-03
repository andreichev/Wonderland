//
//  IndexBuffer.hpp
//  Neverland
//
//  Created by Admin on 15.07.2021.
//

#pragma once

class IndexBuffer {
private:
    unsigned int m_RendererID;
    unsigned int m_Size;

public:
    IndexBuffer(unsigned int *data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;
    unsigned int getSize() const;
};
