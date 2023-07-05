//
// Created by Маргарита  on 03.07.2023.
//

#ifndef TSP_GA_CONTROLLERUI_H
#define TSP_GA_CONTROLLERUI_H

#include "../../data-structures/Graph.h"
#include <iostream>
#include "Settings.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

class ControllerUI
{
public:
    Settings settings;

    //ControllerUI();

    void initFile(std::string sourceFile);
    void initAdd(std::vector<std::pair<int, std::pair<int, int>>> list_edge, int n);
    void initRandom(int n = 0);
    const graph_t & getGraph();
private:
    void initMax(int n);
    graph_t graph;
};

#endif //TSP_GA_CONTROLLERUI_H
