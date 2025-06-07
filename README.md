# Graphics Sandbox

## Dependencies
* [CMake](https://cmake.org/download/) at least version 3.25
* A compiler that supports C++20
* Currently Linux only

## Installation

Clone using 

``git clone --recurse-submodules https://github.com/johnmanardiii/graphics-sandbox.git``

``cd graphics-sandbox``

Install graphics dependencies with:
``./scripts/linux-setup.sh`` (TODO: will be OS-independent later)

### CMake Steps:

Create a binary directory, run the cmake configuration step, then build the binary:

```
mkdir build
cd build
cmake ..
cmake --build .
```

# TODO:
* install and include GLFW and link it to the exe
* get a hello world program that shows a GLFW screen
* Configure it to work with CLion
* Test building on windows
* Ask about if /build directory should be created manually versus by profile
* How to get debug / release profiles and what that means on the compiler end
* Understand when to clean the binary dir + how that should be done for this project
* Test vcpkg installing libraries