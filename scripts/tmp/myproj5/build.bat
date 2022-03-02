@ECHO OFF
:: Builds myproj5
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building myproj5 in Debug..
cmake --build . --config=Debug

ECHO Building myproj5 in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run myproj5 in build/out
