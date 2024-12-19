@echo off

set NAME=jdl

if not exist build (
    mkdir build
)
cd build

cmake -S .. -B . -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . -j8

copy "%NAME%.exe" "../%NAME%.exe"
pause