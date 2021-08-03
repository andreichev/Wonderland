//
//  VertexBufferLayout.hpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#pragma once
#include <OpenGLES/ES3/gl.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // texCoords
    glm::vec2 TexCoords;

    Vertex(glm::vec3 aPosition, glm::vec2 aTexCoords)
        : Position(aPosition)
        , TexCoords(aTexCoords){};
};

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
                return 4;
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
        }
        assert(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout()
        : m_Stride(0) {}
    ~VertexBufferLayout(){};

    template<typename T>
    void push(unsigned int count) {
        assert(false);
    }

    template<>
    void push<float>(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
    }

    template<>
    void push<unsigned int>(unsigned int count) {
        VertexBufferElement element = {GL_UNSIGNED_INT, count, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    void push<char>(unsigned int count) {
        VertexBufferElement element = {GL_UNSIGNED_BYTE, count, GL_TRUE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
    }

    template<>
    void push<glm::vec3>(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count * 3, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT) * 3;
    }

    template<>
    void push<glm::vec2>(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count * 2, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT) * 2;
    }

    void pushVector() {
        // positions
        push<glm::vec3>(1);
        // texture coordinates
        push<glm::vec2>(1);
    }

    inline const std::vector<VertexBufferElement> getElements() const {
        return m_Elements;
    }
    inline unsigned int getStride() const {
        return m_Stride;
    }
};
