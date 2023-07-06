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



add_executable(TSP_GA src/main.cpp src/ui/mainwindow.cpp src/data-structures/Population.h
        src/data-structures/Population.cpp src/data-structures/Graph.h src/data-structures/Chromosome.h
        src/data-structures/PopulationList.h src/algorithm/Algorithm.cpp src/algorithm/Algorithm.h
        src/mating/mating.cpp src/mating/mating.h src/parents-selection/RouletteWheelSelection.h
        src/parents-selection/RouletteWheelSelection.cpp src/new-generation-selection/NewGenerationSelection.h
        src/new-generation-selection/NewGenerationSelection.cpp
        src/ui/controller/ControllerUI.cpp
        src/ui/controller/ControllerUI.h src/ui/controller/CheckData.cpp
        src/ui/controller/CheckData.h src/ui/controller/Settings.h src/randomizer/Randomizer.cpp src/randomizer/Randomizer.h
        src/ui/dialog.cpp src/ui/dialog.h src/ui/dialog.ui
        )

target_link_libraries(TSP_GA
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        qcustomplot
        )

