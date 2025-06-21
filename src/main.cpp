#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

void framebuffer_size_callback(GLFWwindow* /*window*/, int width, int height)
{
    std::cout << "resizing window" << std::endl;
    glViewport(0, 0, width, height);
}

int setupWindowAndRun()
{
    // set GLFW error callback
    glfwSetErrorCallback(error_callback);

    // set OpenGL properties to be core profile and 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int initialWindowWidth = 640;
    int initialWindowHeight = 480;
    GLFWwindow* window = glfwCreateWindow(initialWindowWidth, initialWindowHeight, "My Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    framebuffer_size_callback(window, initialWindowWidth, initialWindowHeight);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    return EXIT_SUCCESS;
}

int main()
{
    int glfwInitResult = glfwInit();
    if(glfwInitResult != GLFW_TRUE)
    {
        std::cout << "Failed to initialize glfw, failed with exit code: " <<
            glfwInitResult << ", exiting the program\n";
        return -1;
    }

    int result = setupWindowAndRun();

    glfwTerminate();    // ensure this is always called to clean up window resources

    return result;
}