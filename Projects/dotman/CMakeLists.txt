cmake_minimum_required(VERSION 4.0.0)
project(dotman VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dotman
   src/main.cpp
   src/App.cpp
   src/cli/ArgumentParser.cpp
   src/core/Dotfile.cpp
   src/core/DotfileManager.cpp
   src/fs/FileSystem.cpp
)

target_include_directories(dotman PRIVATE src)