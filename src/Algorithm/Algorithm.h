//
// Created by karim on 3/07/23.
//

#ifndef TSP_GA_ALGORITHM_H
#define TSP_GA_ALGORITHM_H

#include <vector>
#include <algorithm>
#include <random>

#include "../data-structures/Graph.h"
#include "../data-structures/Population.h"
#include "../data-structures/PopulationList.h"

class Algorithm {
public:
    const graph_t &graph;
    int population_size;

    Algorithm(const graph_t &graph, int population_size);

    Population Gen_I();
};


#endif //TSP_GA_ALGORITHM_H
