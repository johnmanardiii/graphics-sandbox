cmake_minimum_required(VERSION 3.25)

set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")

include(cmake/ensure_vcpkg.cmake)
ensure_vcpkg(${VCPKG_ROOT})

# Set CMake to use vcpkg's custom toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")


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

set(SOURCES
        src/main.cpp
        src/application/application.cpp
        src/application/application.cpp
)

set(HEADERS
        src/application/application.hpp
        src/application/application.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE src)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
    glad::glad
    imgui::imgui
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenGLSandbox)