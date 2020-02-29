cmake_minimum_required(VERSION 3.1.0)

project(simulation)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(INC
)

set(TSRC
)

set(SRC
    src/SpiralGalaxy.cc
    src/SGIterator.cc

    src/SGCelestial.cc
    src/SGStar.cc
    src/SGOrbitCalculator.cc
    src/SGObjectHandler.cc

    src/EGIntensityFunction.cc
    src/SGDiskIntensityFunction.cc
    src/SGIntensityFunction.cc

    src/SGVerticalDistributor.cc
    src/SGDiskRadiusDistributor.cc
)

add_library(simulation SHARED
    ${SRC}
)

target_include_directories(simulation
    PUBLIC
        "inc"
        "../gamma/inc"
)

