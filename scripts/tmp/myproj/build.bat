@ECHO OFF
:: Builds myproj
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO Building myproj in Debug..
cmake --build . --config=Debug

ECHO Building myproj in Release..
cmake --build . --config=Release

ECHO ::
ECHO Run myproj in build/out
