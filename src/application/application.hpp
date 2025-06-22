#pragma once
#include <imgui.h>
#include <glad/glad.h>  // here because glad wants to be included first
#include <GLFW/glfw3.h>

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


