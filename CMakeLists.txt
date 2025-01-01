cmake_minimum_required(VERSION 3.24)
project(DNN)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# source files
set(SOURCE_FILES
    net_construct.h
    HyperParams.h
    Propagation.h
    net_construct.cpp
    HyperParams.cpp
    Propagation.cpp
    main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})