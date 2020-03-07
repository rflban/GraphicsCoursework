cmake_minimum_required(VERSION 3.1.0)

project(sgrenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g3 -fsanitize=address,undefined -fno-omit-frame-pointer")

add_subdirectory(app)
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
    inc/QImageBuffer.h

    inc/Scene.h
    inc/Camera.h
    inc/PerspectiveCube.h
    inc/Vector.h
    inc/Matrix.h
    inc/InputBuffer.h
    inc/Affine.h

    inc/Container.h

    inc/Utility.h


    inc/other/specrend.h
)

set(SRC
    src/main.cc

    src/View.cc
    src/Presenter.cc

    src/mainwindow.cc
    src/DrawingSurface.cc
    src/QImageBuffer.cc

    src/Scene.cc
    src/Camera.cc
    src/PerspectiveCube.cc
    src/Vector2d.cc
    src/Vector3d.cc
    src/Vector4d.cc
    src/Matrix4d.cc


    src/other/specrend.cpp
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

        "inc/other"
)

target_link_libraries(sgrenderer
    Qt5::Widgets

    gamma
    gcwimg
    simulation
)

