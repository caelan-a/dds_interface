@ECHO OFF
:: Setup DDS Interface Wrapper static lib build environment
set PROJECT_ROOT=%~dp0

cd %PROJECT_ROOT%
if not exist "build" mkdir build
cd build

ECHO Generating build files..
cmake ../

ECHO ::
ECHO Open DDS Interface Wrapper Visual Code solution at /build/dds_interface.sln
ECHO Alternatively, build directly with build.bat