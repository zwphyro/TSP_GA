#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../randomizer/Randomizer.h"
#include "mating.h"
#include "../parents-selection/RouletteWheelSelection.h"
// Mating class implementation


/*
Constructor
*/
Mating::Mating(int chromosome_size, int amount_of_crossover_dots, double mutation_probability)
{
    this->chromosome_size = chromosome_size;
    this->amount_of_crossover_dots = amount_of_crossover_dots;
    this->mutation_probability = mutation_probability;
}


/*
Perform ordered crossover on two parent chromosomes
*/
chromosome_t
Mating::ordered_crossover(const chromosome_t &first_parent, const chromosome_t &second_parent, int crossover_start,
                          int crossover_end)
{
    // Create a new path with the same length as parents, initialized with 'x' in each element
    std::vector<int> offspring(second_parent.begin(), second_parent.begin() + crossover_start);

    // Fill in the offspring with a part of the first parent
    offspring.insert(offspring.end(), first_parent.begin() + crossover_start, first_parent.begin() + crossover_end);
    offspring.insert(offspring.end(), second_parent.begin() + crossover_end, second_parent.end());

    // Create a map to track the instances of each gene in the offspring
    std::map<int, std::vector<int>> map;
    for (int i = 0; i < chromosome_size; i++)
    {
        map[i] = std::vector<int>();
    }

    // Populate the map with gene indices
    for (int i = 0; i < chromosome_size; i++)
    {
        map[offspring[i]].push_back(i);
    }

    // Identify zero instances and multiple instances of genes
    std::vector<int> zero_instances;
    std::vector<int> multiple_instances;

    for (auto &item: map)
    {
        if (item.second.empty())
        {
            zero_instances.push_back(item.first);
        } else if (item.second.size() > 1)
        {
            multiple_instances.push_back(item.first);
        }
    }

    // Resolve multiple instances by randomly assigning zero instances to them
    for (int multiple_instance_gen: multiple_instances)
    {
        while (map[multiple_instance_gen].size() > 1)
        {
            Randomizer randomizer;

            int random_multiple_instance_index = randomizer.getRandomInt(0,
                                                                         (int) map[multiple_instance_gen].size() - 1);
            int random_zero_instance_gen = randomizer.getRandomInt(0, (int) zero_instances.size() - 1);

            offspring[map[multiple_instance_gen][random_multiple_instance_index]] = zero_instances[random_zero_instance_gen];
            map[multiple_instance_gen].erase(map[multiple_instance_gen].begin() + random_multiple_instance_index);
            zero_instances.erase(zero_instances.begin() + random_zero_instance_gen);
        }
    }

    return offspring;
}


/*
Perform mutation on a chromosome by swapping genes
*/
void Mating::mutation(chromosome_t &chromosome, int mutation_rate)
{
    Randomizer randomizer;

    for (int i = 0; i < mutation_rate; i++)
    {
        int position_1 = randomizer.getRandomInt(0, chromosome_size - 1);
        int position_2 = randomizer.getRandomInt(0, chromosome_size - 1);

        std::swap(chromosome[position_1], chromosome[position_2]);
    }
    modifyOrder(chromosome);
}


/*
Perform mutation on a chromosome by reversing a segment of genes
*/
void Mating::mutationSwitch(chromosome_t &chromosome, int mutation_rate)
{
    Randomizer randomizer;

    for (int i = 0; i < mutation_rate; i++)
    {
        int position_1 = randomizer.getRandomInt(0, chromosome_size - 1);
        int position_2 = randomizer.getRandomInt(0, chromosome_size - 1);

        std::reverse(chromosome.begin() + position_1, chromosome.begin() + position_2 + 1);
    }
    modifyOrder(chromosome);
}


/*
Get children from the population using crossover and mutation
*/
std::vector<chromosome_t> Mating::getChildren(const Population &population)
{
    RouletteWheelSelection selector(population);
    std::vector<chromosome_t> children;
    children.reserve(population.size());

    int crossover_start = 0;
    int crossover_end;

    Randomizer randomizer;

    for (int i = 0; i < population.size(); i++)
    {
        crossover_end = randomizer.getRandomInt(0, chromosome_size - 1);
        if (amount_of_crossover_dots == 2)
        {
            crossover_start = randomizer.getRandomInt(0, chromosome_size - 1);
            if (crossover_start > crossover_end) std::swap(crossover_start, crossover_end);
        }

        auto &first_parent = selector.getIndividual();
        auto &second_parent = selector.getIndividual();
        children.emplace_back(ordered_crossover(first_parent, second_parent, crossover_start, crossover_end));
        mutation(children.back(), (int) (mutation_probability * chromosome_size));
    }

    return children;
}


/*
Get mutated individuals from the population
*/
std::vector<chromosome_t> Mating::getMutated(const Population &population)
{
    RouletteWheelSelection selector(population);
    std::vector<chromosome_t> mutated_individuals;
    mutated_individuals.reserve(chromosome_size);

    for (int i = 0; i < chromosome_size; i++)
    {
        mutated_individuals.emplace_back(selector.getIndividual());
        mutationSwitch(mutated_individuals.back(), 1);
    }

    return mutated_individuals;
}


/*
Modify the order of the chromosome by moving the '0' gene to the beginning
*/
void Mating::modifyOrder(chromosome_t &chromosome)
{
    int zero_index = 0;
    for (int i = 0; i < chromosome_size; i++)
    {
        if (chromosome[i] == 0)
        {
            zero_index = i;
            break;
        }
    }
    chromosome.insert(chromosome.end(), chromosome.begin(), chromosome.begin() + zero_index);
    chromosome.erase(chromosome.begin(), chromosome.begin() + zero_index);
}
