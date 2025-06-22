#pragma once
#include <glad/glad.h>  // here because glad wants to be included first
#include <GLFW/glfw3.h>

class Platform
{
public:
    Platform() = default;
    bool initialize(int windowWidth, int windowHeight, const char* windowTitle);
    ~Platform();

    Platform(const Platform&) = delete;
    Platform& operator=(const Platform&) = delete;
    Platform(Platform&&) = delete;
    Platform& operator=(Platform&&) = delete;

    GLFWwindow* window = nullptr;
};


