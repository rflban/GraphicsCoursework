cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

project(app)

set(SRC
    src/main.cc
)

add_executable(app
    ${SRC}
)

target_link_libraries(app
    gamma
    gcwimg
    simulation
)

target_include_directories(app
    PUBLIC
        "inc"
        "../imagegenerator/inc"
        "../simulation/inc"
        "../gamma/inc"
)

