cmake_minimum_required(VERSION 3.1.0)

project(gcw_imagegenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(INC
)

set(TSRC
)

set(SRC
    src/main.cc

    src/Pixmap.cc
    src/Painter.cc
    src/PPMGenerator.cc
)

add_executable(gcw_imagegenerator
    ${INC}
    ${TSRC}
    ${SRC}
)

target_include_directories(gcw_imagegenerator
    PUBLIC
        "inc"
)

