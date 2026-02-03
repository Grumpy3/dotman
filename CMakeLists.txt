cmake_minimum_required(VERSION 3.20)
project(dotman VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(dotman_lib
   src/App.cpp
   src/cli/ArgumentParser.cpp
   src/core/Dotfile.cpp
   src/core/DotfileManager.cpp
   src/fs/FileSystem.cpp
)

target_include_directories(dotman_lib PUBLIC src)

# 2. The main executable
add_executable(dotman src/main.cpp)
target_link_libraries(dotman PRIVATE dotman_lib)

# 3. The test executable
add_executable(dotman_tests tests/test_install.cpp)
target_link_libraries(dotman_tests PRIVATE dotman_lib)


enable_testing()
add_test(NAME dotman_tests COMMAND dotman_tests)