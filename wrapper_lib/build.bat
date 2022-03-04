@ECHO OFF

ECHO Building static library for DDS Interface on windows..
set PROJECT_ROOT=%~dp0
ECHO "Project root: %PROJECT_ROOT%"
ECHO:

cd %PROJECT_ROOT%
if not exist "build" (
    :: Make sure project has been setup
    ECHO build environment hasnt been generated yet
    ./setup.bat
)

cd build

ECHO Building static library with Debug config..
cmake --build . --config=Debug

ECHO Building static library with Release config..
cmake --build . --config=Release

ECHO:
ECHO Builds complete! Output libs can be found in /build/out/lib..