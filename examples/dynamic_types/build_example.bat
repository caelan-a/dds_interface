@ECHO OFF
:: Builds example
set PROJECT_ROOT=%~dp0

ECHO Creating DynamicTypes Example..
cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building example in Debug..
cmake --build . --config=Debug

ECHO Building example in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run examples in build/out