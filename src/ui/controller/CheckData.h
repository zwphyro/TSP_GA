//
// Created by Маргарита  on 03.07.2023.
//

#ifndef TSP_GA_CHECKDATA_H
#define TSP_GA_CHECKDATA_H

#include "../../data-structures/Graph.h"
#include <limits.h>
class CheckData
{

public:
    bool checkGraph(graph_t& graph);
    int addEdge(std::vector<std::pair<int, std::pair<int, int>>>& list_edge, int distance, int departure, int arrival, int n);

};

#endif //TSP_GA_CHECKDATA_H
