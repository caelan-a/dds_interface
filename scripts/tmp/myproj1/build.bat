@ECHO OFF
:: Builds myproj1
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building myproj1 in Debug..
cmake --build . --config=Debug

ECHO Building myproj1 in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run myproj1 in build/out
