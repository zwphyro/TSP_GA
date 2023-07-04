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
    graph_t graph;
    Settings settings;

    //ControllerUI();

    const graph_t &initFile(std::string sourceFile);
    const graph_t &initAdd(std::vector<std::pair<int, std::pair<int, int>>> list_edge, int n);
    const graph_t &initRandom(int n = 0);

    void check();
private:
    void initMax(int n);
};


#endif //TSP_GA_CONTROLLERUI_H
