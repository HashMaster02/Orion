#include "Orion/Renderer.h"
#include "glad/glad.h"

namespace Orion {
    void bind_vertex_array(unsigned int VAO) {
        glBindVertexArray(VAO);
    }

    void draw(unsigned int total_vertices) {
        glDrawArrays(GL_TRIANGLES, 0, total_vertices);
    }
}