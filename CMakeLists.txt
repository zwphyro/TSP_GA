cmake_minimum_required(VERSION 3.25)
project(TSP_GA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        )

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


add_executable(TSP_GA src/main.cpp src/ui/mainwindow.cpp src/data-structures/Population.h src/data-structures/Population.cpp src/data-structures/Graph.h src/data-structures/Chromosome.h src/data-structures/PopulationList.h src/parents-selection/RouletteWheelSelection.h src/parents-selection/RouletteWheelSelection.cpp)

target_link_libraries(TSP_GA
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

