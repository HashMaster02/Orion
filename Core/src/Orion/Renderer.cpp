#include "Orion/Renderer.h"
#include "glad/glad.h"

namespace Orion {
    void bind_vertex_array(unsigned int VAO) {
        glBindVertexArray(VAO);
    }

    void use_shader(unsigned int shader) {
        glUseProgram(shader);
    }
}