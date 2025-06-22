#define GLFW_INCLUDE_NONE
#include "platform/platform.hpp"

// todo: move these to an application file
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    Platform platform;

    if (!platform.initialize(1280, 720, "GLFW Window"))
    {
        return -1;
    }

    while (!glfwWindowShouldClose(platform.window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(platform.window);
        glfwPollEvents();
    }

    return 0;
}