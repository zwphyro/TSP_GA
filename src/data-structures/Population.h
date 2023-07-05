#ifndef TSP_GA_POPULATION_H
#define TSP_GA_POPULATION_H

#include <vector>
#include "Chromosome.h"
#include "Graph.h"

/*
 * Population is a group of interacting chromosomes (individuals), that formed at each step of the algorithm
 */
class Population
{
public:
    Population(const std::vector<chromosome_t> &individuals, const graph_t &graph);
    const std::vector<long> &getFitnessValues() const;
    const std::vector<chromosome_t> &getIndividuals() const;
    std::pair<const chromosome_t &, int> getBestIndividual() const;
    std::pair<const chromosome_t &, int> getWorstIndividual() const;
    const chromosome_t &operator[](unsigned int index) const;
    std::size_t size() const;

private:
    std::vector<chromosome_t> individuals;
    std::vector<long> fitness_values;
    int best_individual_index;
    int worst_individual_index;

};

#endif //TSP_GA_POPULATION_H
