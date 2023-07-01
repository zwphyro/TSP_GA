#ifndef TSP_GA_POPULATION_H
#define TSP_GA_POPULATION_H

#include <vector>

/*
 * Graph is defined as adjacency matrix
 * Each index of matrix corresponds to the graph node
 */
typedef std::vector<std::vector<int>> graph_t;

/*
 * Chromosome is defined as vector of nodes indexes which form a Hamiltonian cycle
 */
typedef std::vector<int> chromosome_t;

/*
 * Population is a group of interacting chromosomes (individuals), that formed at each step of the algorithm
 */
class Population
{
public:
    Population(const std::vector<chromosome_t> &individuals, const graph_t &graph);
    const std::vector<long> &get_fitness_values();
    const std::vector<chromosome_t> &get_individuals();
    const std::pair<chromosome_t, int> &get_best_individual();
    const chromosome_t &operator[](unsigned int index);

private:
    std::vector<chromosome_t> individuals;
    std::vector<long> fitness_values;
    int best_individual_index;

};


#endif //TSP_GA_POPULATION_H
