cmake_minimum_required(VERSION 3.25)
project(glfw_and_cmake LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

find_package(OpenGL REQUIRED)
add_executable(glfw_and_cmake main.cpp)
target_link_libraries(glfw_and_cmake PRIVATE glad glfw)
