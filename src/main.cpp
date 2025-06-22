#define GLFW_INCLUDE_NONE
#include "application/application.hpp"

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