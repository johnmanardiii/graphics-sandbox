#pragma once
#include <glad/glad.h>  // here because glad wants to be included first
#include <GLFW/glfw3.h>

/*
 *  In charge of setting up initialization of libraries that can be set up without knowing the context
 *  of the application, mainly glfwInit. The application is in charge of initializing windows and gl contexts,
 *  as well as glad, since that needs to be done after the context is set (and therefore after glfw window creation)
 */
class Application
{
public:
    Application() = default;
    ~Application();

    bool initialize(int windowWidth, int windowHeight, const char* windowTitle);
    void run();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(Application&&) = delete;

    GLFWwindow* window = nullptr;
};


