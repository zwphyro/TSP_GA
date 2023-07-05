#include "Population.h"

/*
 * Constructor initializing all fields of the class, also calculates the cycle length for each individual
 * to define the fitness function value
 */
Population::Population(const std::vector<chromosome_t> &individuals, const graph_t &graph)
{
    this->individuals = individuals;
    fitness_values.reserve(individuals.size());

    best_individual_index = 0;
    worst_individual_index = 0;

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
        if (fitness_values.back() > fitness_values[worst_individual_index])
        {
            worst_individual_index = fitness_values.size() - 1;
        }
    }
}

/*
 * Returns fitness function values of all individuals
 */
const std::vector<long> &Population::getFitnessValues() const
{
    return fitness_values;
}

/*
 * Returns chromosomes of all individuals
 */
const std::vector<chromosome_t> &Population::getIndividuals() const
{
    return individuals;
}

/*
 * Returns chromosome and fitness function value of individual with smallest fitness value in population
 */
std::pair<const chromosome_t &, int> Population::getBestIndividual() const
{
    return {individuals[best_individual_index], fitness_values[best_individual_index]};
}

/*
 * Returns chromosome and fitness function value of individual with the largest fitness value in population
 */
std::pair<const chromosome_t &, int> Population::getWorstIndividual() const
{
    return {individuals[worst_individual_index], fitness_values[worst_individual_index]};
}

/*
 * Returns chromosome of individual at defined index
 */
const chromosome_t &Population::operator[](unsigned int index) const
{
    return individuals[index];
}

/*
 * Returns amount of individuals in population
 */
std::size_t Population::size() const
{
    return individuals.size();
}
