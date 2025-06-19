@echo off
setlocal

echo Setting up for Windows development...

if "%1"=="clean" (
    echo Deleting build-windows if present...
    if exist "build-windows" (
        rmdir /s /q "build-windows"
        echo Build directory deleted
    )
    else (
        echo No build directory to delete.
    )
)

if not exist "build-windows" (
    echo Creating Windows build directory build-windows
    mkdir build-windows
    if errorlevel 1 (
        echo Failed to create build-windows directory
        exit /b 1
    )
)

cd build-windows

echo Configuring with Visual Studio 2022

cmake -G "Visual Studio 17 2022" ^
        -DCMAKE_BUILD_TYPE=Release ^
        ..

if errorlevel 1 (
    echo CMake configuration Failed
    exit /b 1
)