# wrapper for clang build
export CC=`which clang`
export CXX=`which clang++`
cd build
cmake ..
cd ..
