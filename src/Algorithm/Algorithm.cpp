//
// Created by karim on 3/07/23.
//

#include "Algorithm.h"
#include<iostream>

Algorithm::Algorithm(const graph_t &graph, int population_size) : graph(graph), population_size(population_size)
{

}

Population Algorithm::Gen_I()
{
    std::vector<chromosome_t> generation;
    for (int i = 0; i < population_size; i++)
    {
        generation.emplace_back(graph.size());
        auto &currant_individual = generation.back();

        std::iota(currant_individual.begin(), currant_individual.end(), 0);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(currant_individual.begin(), currant_individual.end(), gen);
    }

    for (int i = 0; i < generation.size(); i++)
    {
        for (int j = 0; j < generation[i].size(); j++)
        {
            std::cout << generation[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return {generation, graph};
}
