#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Minimal Window", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}