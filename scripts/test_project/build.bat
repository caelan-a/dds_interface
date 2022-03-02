@ECHO OFF
:: Builds test_project
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building test_project in Debug..
cmake --build . --config=Debug

ECHO Building test_project in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run test_project in build/out
