cmake_minimum_required(VERSION 3.25)
project(TSP_GA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(Qt5_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt5")


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TSP_GA src/main.cpp src/crossover/demo_cross_mut.cpp src/crossover/demo_cross_mut.h)
target_link_libraries(TSP_GA
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

