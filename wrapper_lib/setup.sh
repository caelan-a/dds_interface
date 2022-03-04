
# Builds example project
PROJECT_ROOT=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $PROJECT_ROOT
mkdir -p "build"
cd build

echo "Generating build files.."
cmake ../

echo "Run build.sh to build project"