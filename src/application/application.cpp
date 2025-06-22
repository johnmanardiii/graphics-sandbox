#include "application/application.hpp"
#include <iostream>

bool Application::initialize(const int windowWidth, const int windowHeight, const char* windowTitle)
{
    int glfwInitResult = glfwInit();
    if(glfwInitResult != GLFW_TRUE)
    {
        std::cout << "Failed to initialize glfw, failed with exit code: " <<
            glfwInitResult << ", exiting the program\n";
        return false;
    }

    // set OpenGL properties to be core profile and 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, nullptr, nullptr);
    if (!window)
    {
        std::cout << "Failed to create glfw window" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    return true;
}

void Application::run()
{
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Application::~Application()
{
    if (window)
    {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}
