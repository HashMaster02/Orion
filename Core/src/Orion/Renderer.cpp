#include "Orion/Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Orion {
    float lastFrame = 0.0f;

    void bind_vertex_array(unsigned int VAO) {
        glBindVertexArray(VAO);
    }

    void draw(unsigned int total_vertices) {
        glDrawArrays(GL_TRIANGLES, 0, total_vertices);
    }

    float delta_time() {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        return deltaTime;
    }
}