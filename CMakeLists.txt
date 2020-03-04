cmake_minimum_required(VERSION 3.1.0)

project(sgrenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

add_subdirectory(gamma)
add_subdirectory(simulation)
add_subdirectory(imagegenerator)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS
    "forms"
)

set(INC
    inc/View.h
    inc/ViewObserver.h
    inc/Presenter.h

    inc/mainwindow.h
    inc/DrawingSurface.h

    inc/Container.h

    inc/Utility.h
)

set(SRC
    src/main.cc

    src/View.cc
    src/Presenter.cc

    src/mainwindow.cc
    src/DrawingSurface.cc
)

set(FRM
    forms/mainwindow.ui
)

set(RES
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(sgrenderer
    ${INC}
    ${SRC}
    ${FRM}
    ${RES}
)

target_include_directories(sgrenderer
    PUBLIC
        "inc"
        "imagegenerator/inc"
        "simulation/inc"
        "gamma/inc"
)

target_link_libraries(sgrenderer
    Qt5::Widgets

    gamma
    gcwimg
    simulation
)

