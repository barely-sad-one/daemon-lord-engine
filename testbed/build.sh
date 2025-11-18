#!/usr/bin/env sh

cmd="$1"

if [ ! -d "build" ]; then
    mkdir build
fi

cd build || {
    echo "Failed to enter build directory"
    exit 1
}

if [ "$cmd" = "debug" ]; then
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    cmake --build .
elif [ "$cmd" = "release" ]; then
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
elif [ "$cmd" = "clean" ]; then
    cmake --build . --target clean
else
    echo "Usage: $0 [debug|release|clean]"
    exit 1
fi

cd ..
