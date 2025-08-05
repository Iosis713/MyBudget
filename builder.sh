#!/bin/bash
cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++-18 -DCMAKE_PREFIX_PATH="$HOME/QT/6.7.3/gcc_64" -DCMAKE_CXX_CLANG_TIDY=clang-tidy
cmake --build build
ln -sf build/compile_commands.json .
