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
    // const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // scale up to have consistent visual size
    float xscale, yscale;
    glfwGetMonitorContentScale(glfwGetPrimaryMonitor(), &xscale, &yscale);
    const float contentScale = yscale / xscale;
    window = glfwCreateWindow(
        static_cast<int>(windowWidth * contentScale),
        static_cast<int>(windowHeight * contentScale),
        windowTitle,
        nullptr,
        nullptr);
    if (!window)
    {
        std::cout << "Failed to create glfw window" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // enable vsync

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    // glViewport(0, 0, width, height);

    return true;
}

void Application::run()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        // glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
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
