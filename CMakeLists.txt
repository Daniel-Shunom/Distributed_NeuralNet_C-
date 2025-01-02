cmake_minimum_required(VERSION 3.24)
project(DNN_)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/DNN_)

# Add source files
file(GLOB_RECURSE SOURCES "DNN_/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
