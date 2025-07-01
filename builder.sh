!#/bin/bash
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$HOME/QT/6.7.3/gcc_64 ..
make -j
