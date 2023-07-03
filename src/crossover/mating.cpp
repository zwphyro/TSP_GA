#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

#include "mating.h"

chromosome_t Mating::ordered_crossover(const chromosome_t &parent_1, const chromosome_t &parent_2, int crossover_start,
                                       int crossover_end) {

    std::vector<int> offspring(parent_1.begin(), parent_1.begin() +
                                                 crossover_end);        // create new path with same len as parents with x in each elem

    offspring.insert(offspring.end(), parent_2.begin() + crossover_end,
                     parent_2.end());  // fill into offspring a part of parent_1

    std::map<int, std::vector<int>> map;

    for (int i = 0; i < offspring.size(); i++) {
        map[i] = std::vector<int>();
    }

    for (int i = 0; i < offspring.size(); i++) {
        map[offspring[i]].push_back(i);
    }

    std::vector<int> zero_instances;
    std::vector<int> mult_instances;

    for (auto &item: map) {
        if (item.second.size() == 0) {
            zero_instances.push_back(item.first);
        } else if (item.second.size() > 1) {
            mult_instances.push_back(item.first);
        }
    }

    for (int i = 0; i < mult_instances.size(); i++) {
        while (map[mult_instances[i]].size() > 1) {
            std::random_device rd;            // rand num form internet
            std::mt19937 gen(rd());            // might not be correct
            std::uniform_int_distribution<int> index(0, (int) map[mult_instances[i]].size() - 1);
            std::uniform_int_distribution<int> city(0, (int) zero_instances.size() - 1);

            int rand_index = index(gen);
            int rand_city = city(gen);

            offspring[map[mult_instances[i]][rand_index]] = zero_instances[rand_city];
            map[mult_instances[i]].erase(map[mult_instances[i]].begin() + rand_index);
            zero_instances.erase(zero_instances.begin() + rand_city);
        }
    }

    return offspring;
}

chromosome_t Mating::mutation(const chromosome_t &chromosome, int mutation_rate) {
    std::vector<int> offspring;         // for storing mutated path
    std::vector<int> possible_positions; // for possible index
    for (int i = 0; i < chromosome.size(); i++) {
        offspring.push_back(chromosome[i]);    // copy of path in chromosome
    }

    for (int i = 0; i < offspring.size(); i++) {
        possible_positions.push_back(i);            // create indexes
    }

    std::random_device rd;            // rand num form internet
    std::mt19937 gen(rd());            // might not be correct
    std::uniform_int_distribution<int> dist(0, possible_positions.size() - 1);

    for (int i = 0; i < mutation_rate; i++) {
        int position_1 = dist(gen);
        int position_2 = dist(gen);        // just swaps two cities

        std::swap(offspring[position_1], offspring[position_2]);
    }

    return offspring;
}
