#ifndef TSP_GA_POPULATION_H
#define TSP_GA_POPULATION_H

#include <vector>

typedef std::vector<int> chromosome_t;
typedef std::vector<std::vector<int>> graph_t;

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
