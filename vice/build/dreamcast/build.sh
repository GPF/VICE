SOURCE_DIR="${PWD}/../.."
cmake -DCMAKE_TOOLCHAIN_FILE="$KOS_CMAKE_TOOLCHAIN"  "$SOURCE_DIR" 
make x64
