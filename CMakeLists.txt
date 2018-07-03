
cmake_minimum_required(VERSION 2.8)
project(cpp-cmake-examples)

#include(GNUInstallDirs)

# This are options which can be turned on or of when configuring the build
# e.g. cmake .. -DBUILD_HELLO_WORLD=OFF
option(BUILD_APP "Build main application" ON) 
option(BUILD_HELLO_WORLD "Build Hello World application" ON) 

# If you need support for custom CMAKE modules, you can use this command. 
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find packages, in this case OpenCV
find_package( OpenCV REQUIRED )

# Add include dirs. 
# You can use vars from find_package or vars you declared yourself. 
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Sets the compiler flags for this project. These flags are passed to your C++ compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wunreachable-code -std=c++1y -O3 -g")

# Descend into subdirectory src
add_subdirectory(src)
