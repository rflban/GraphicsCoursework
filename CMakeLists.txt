cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

project(fnabiev_gcw)

add_subdirectory(app)
add_subdirectory(gamma)
add_subdirectory(imagegenerator)

