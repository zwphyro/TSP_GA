//
// Created by karim on 3/07/23.
//

#ifndef TSP_GA_ALGORITHM_H
#define TSP_GA_ALGORITHM_H

#include "../data-structures/PopulationList.h"

/*
 * Class that implements genetic algorithm interface
 */
class Algorithm
{
public:
    Algorithm(const graph_t &graph, int population_size);
    const Population &getCurrentPopulation() const;
    int switchToNextPopulation();
    int switchToPreviousPopulation();
    void switchToLastPopulation();

    const graph_t &graph;
    
private:
    int population_size;
    double mutation_probability;
    int amount_of_crossover_dots;
    int max_population_history_size;
    bool end_detector;

    std::list<Population>::iterator current_population;
    population_list_t populations_history;

    void generateFirstPopulation();
};


#endif //TSP_GA_ALGORITHM_H
