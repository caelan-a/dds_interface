
# Builds example project
PROJECT_ROOT=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $PROJECT_ROOT
if [ -d "build" ] 
then
    echo "Build environment already generated.."
else
    ./setup.sh
fi

cd build

echo "Building example in Debug.."
cmake --build . --config=Debug

echo "Building example in Release.."
cmake --build . --config=Release

echo "\nRun examples in build/out"