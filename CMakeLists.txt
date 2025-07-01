cmake_minimum_required(VERSION 3.25)


# Project Settings
project(OpenGLSandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Werror -pedantic)
else()
    message(WARNING "Compiler is not explicitly supported, continue with caution (still building anyways :P)")
endif()

# Library Code (If it gets too long, move to cmake file)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

# glad
add_library(glad STATIC
    /external/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    external/glad/include
)

# Project Code
set(SOURCES
        src/main.cpp
        src/application/application.cpp
)

set(HEADERS
        src/application/application.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE src)


target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenGLSandbox)