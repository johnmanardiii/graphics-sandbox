#pragma once
#include <GLFW/glfw3.h>

class ImGuiRenderer
{
public:
    explicit ImGuiRenderer(GLFWwindow* window) : window(window) {}
    ~ImGuiRenderer();

    ImGuiRenderer(const ImGuiRenderer&) = delete;
    ImGuiRenderer& operator=(const ImGuiRenderer&) = delete;
    ImGuiRenderer(ImGuiRenderer&&) = delete;
    ImGuiRenderer& operator=(ImGuiRenderer&&) = delete;

private:
    GLFWwindow* window;
};
