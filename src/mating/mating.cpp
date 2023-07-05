#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

#include "mating.h"
#include "../parents-selection/RouletteWheelSelection.h"
#include "../algorithm/Algorithm.h"


Mating::Mating(int chromosome_size, int amount_of_crossover_dots, double mutation_probability)
{
    this->chromosome_size = chromosome_size;
    this->amount_of_crossover_dots = amount_of_crossover_dots;
    this->mutation_probability = mutation_probability;
}

chromosome_t
Mating::ordered_crossover(const chromosome_t &first_parent, const chromosome_t &second_parent, int crossover_start,
                          int crossover_end)
{
    // create new path with same len as parents with x in each elem
    std::vector<int> offspring(second_parent.begin(), second_parent.begin() + crossover_start);

    // fill into offspring a part of first_parent
    offspring.insert(offspring.end(), first_parent.begin() + crossover_start, first_parent.begin() + crossover_end);
    offspring.insert(offspring.end(), second_parent.begin() + crossover_end, second_parent.end());

    std::map<int, std::vector<int>> map;

    for (int i = 0; i < chromosome_size; i++)
    {
        map[i] = std::vector<int>();
    }

    for (int i = 0; i < chromosome_size; i++)
    {
        map[offspring[i]].push_back(i);
    }

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

    for (int multiple_instance_gen: multiple_instances)
    {
        while (map[multiple_instance_gen].size() > 1)
        {
            std::random_device rd;            // rand num form internet
            std::mt19937 gen(rd());            // might not be correct
            std::uniform_int_distribution<int> multiple_instance_index(0, (int) map[multiple_instance_gen].size() - 1);
            std::uniform_int_distribution<int> zero_instance_gen(0, (int) zero_instances.size() - 1);

            int random_multiple_instance_index = multiple_instance_index(gen);
            int random_zero_instance_gen = zero_instance_gen(gen);

            offspring[map[multiple_instance_gen][random_multiple_instance_index]] = zero_instances[random_zero_instance_gen];
            map[multiple_instance_gen].erase(map[multiple_instance_gen].begin() + random_multiple_instance_index);
            zero_instances.erase(zero_instances.begin() + random_zero_instance_gen);
        }
    }

    return offspring;
}

chromosome_t Mating::mutation(chromosome_t &chromosome, int mutation_rate)
{
    std::random_device rd;            // rand num form internet
    std::mt19937 gen(rd());            // might not be correct
    std::uniform_int_distribution<int> dist(0, chromosome.size() - 1);

    for (int i = 0; i < mutation_rate; i++)
    {
        int position_1 = dist(gen);
        int position_2 = dist(gen);        // just swaps two cities

        std::swap(chromosome[position_1], chromosome[position_2]);
    }

    return chromosome;
}

chromosome_t Mating::mutation_switch(chromosome_t &chromosome, int mutation_rate)
{
    std::random_device rd;            // rand num form internet
    std::mt19937 gen(rd());            // might not be correct
    std::uniform_int_distribution<int> dist(0, chromosome.size() - 1);

    for (int i = 0; i < mutation_rate; i++)
    {
        int position_1 = dist(gen);
        int position_2 = dist(gen);        // just swaps two cities

        std::reverse(chromosome.begin() + position_1, chromosome.begin() + position_2 + 1);
    }

    return chromosome;
}

std::vector<chromosome_t> Mating::getChildren(const Population &population)
{
    RouletteWheelSelection selector(population);
    std::vector<chromosome_t> children;
    children.reserve(population.size());

    int crossover_start = 0;
    int crossover_end;

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(0, chromosome_size - 1);

    for (int i = 0; i < population.size(); i++)
    {
        crossover_end = distribution(generator);
        if (amount_of_crossover_dots == 2)
        {
            crossover_start = distribution(generator);
            if (crossover_start > crossover_end) std::swap(crossover_start, crossover_end);
        }

        auto &first_parent = selector.getIndividual();
        auto &second_parent = selector.getIndividual();
        children.emplace_back(ordered_crossover(first_parent, second_parent, crossover_start, crossover_end));
        mutation(children.back(), (int) (mutation_probability * chromosome_size));
    }

    return children;
}
