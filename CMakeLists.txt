cmake_minimum_required(VERSION 3.25)

set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")

include(cmake/ensure_vcpkg.cmake)
ensure_vcpkg(${VCPKG_ROOT})

# Set CMake to use vcpkg's custom toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Actual Project
project(GLFW_Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
else()
    message(FATAL_ERROR "Only MSVC compiler currently supported")
endif()

add_executable(GLFW_Test src/glfw_hello_world.cpp)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(GLFW_Test PRIVATE glfw)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW_Test)