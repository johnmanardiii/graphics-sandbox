#define GLFW_INCLUDE_NONE
#include "application/application.hpp"

// todo: move these to an application file
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    Application app;

    if (!app.initialize(1280, 720, "GLFW Window"))
    {
        return -1;
    }

    app.run();
    return 0;
}