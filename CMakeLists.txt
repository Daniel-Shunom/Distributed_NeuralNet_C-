cmake_minimum_required(VERSION 3.24)
project(DNN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/DNN)

# Add source files
file(GLOB_RECURSE SOURCES "DNN/*.cpp")
#file(GLOB_RECURSE SOURCES "DNN/*.h")

add_executable(${PROJECT_NAME} ${SOURCES})