#include "Population.h"

Population::Population(const std::vector<chromosome_t> &individuals, const graph_t &graph)
{
    this->individuals = individuals;
    fitness_values.reserve(individuals.size());

    best_individual_index = 0;

    for (auto &item: this->individuals)
    {
        long sum = 0;
        for (int i = 1; i < item.size(); i++)
        {
            int previous_node = item[i - 1];
            int current_node = item[i];
            sum += graph[previous_node][current_node];
        }
        sum += graph[item.back()][item.front()];
        fitness_values.emplace_back(sum);

        if (fitness_values.back() < fitness_values[best_individual_index])
        {
            best_individual_index = fitness_values.size() - 1;
        }
    }
}

const std::vector<long> &Population::get_fitness_values()
{
    return fitness_values;
}

const std::vector<chromosome_t> &Population::get_individuals()
{
    return individuals;
}

const std::pair<chromosome_t, int> &Population::get_best_individual()
{
    return std::make_pair(individuals[best_individual_index], fitness_values[best_individual_index]);
}

const chromosome_t &Population::operator[](unsigned int index)
{
    return individuals[index];
}
