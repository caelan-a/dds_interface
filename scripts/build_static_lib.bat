@ECHO OFF

ECHO Building static library for DDS Interface on windows..
set PROJECT_ROOT=%~dp0..
ECHO "Project root: %PROJECT_ROOT%"
ECHO:

ECHO Creating build directory for cmake generated build files..
cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd %PROJECT_ROOT%/build

ECHO Building static library with Debug config..
cmake ../

cmake --build . --config=Debug

ECHO Building static library with Release config..
cmake --build . --config=Release

ECHO:
ECHO Builds complete! Output libs can be found in /build/out/lib..
