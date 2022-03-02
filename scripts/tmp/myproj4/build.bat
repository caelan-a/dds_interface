@ECHO OFF
:: Builds myproj4
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building myproj4 in Debug..
cmake --build . --config=Debug

ECHO Building myproj4 in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run myproj4 in build/out
