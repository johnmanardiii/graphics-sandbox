cmake_minimum_required(VERSION 3.25)

# Set VCPKG paths depdening on OS
set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
if(WIN32)
    set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg")
    set(VCPKG_BOOTSTRAP_SCRIPT "${VCPKG_ROOT}/bootstrap-vcpkg.bat")
else()
    set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg")
    set(VCPKG_BOOTSTRAP_SCRIPT "${VCPKG_ROOT}/bootstrap-vcpkg.sh")
endif()

# Run the bootstrap script if the executable doesn't exist
if(NOT EXISTS ${VCPKG_EXECUTABLE})
    message(STATUS "Running vcpkg bootstrap script")
    execute_process(COMMAND ${VCPKG_BOOTSTRAP_SCRIPT}
                    WORKING_DIRECTORY ${VCPKG_ROOT}
                    RESULT_VARIABLE VCPKG_BOOTSTRAP_RESULT)
    if(NOT VCPKG_BOOTSTRAP_RESULT EQUAL 0)
        message(FATAL_ERROR "vcpkg bootstrap failed, exiting...")
    else()
        message(STATUS "vcpkg bootstrap complete")
    endif()
endif()

# Set CMake to use vcpkg's custom toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Actual Project
project(GLFW_Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
elseif(CMAKE_CXX_COMPILER STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
else()
    message(FATAL_ERROR "Only MSVC and Clang compilers currently supported")
endif()

add_executable(GLFW_Test src/glfw_hello_world.cpp)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(GLFW_Test PRIVATE glfw)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW_Test)