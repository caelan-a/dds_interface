@ECHO OFF
:: Builds @NEW_PROJECT_NAME@
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building @NEW_PROJECT_NAME@ in Debug..
cmake --build . --config=Debug

ECHO Building @NEW_PROJECT_NAME@ in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run @NEW_PROJECT_NAME@ in build/out