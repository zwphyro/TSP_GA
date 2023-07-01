#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include <experimental/random>

struct Genome
{
    std::vector<int> path;
    float fitness;
};

void P(std::vector<int> offspring)
{
    for (int i = 0; i < offspring.size(); i++)
    {
        std::cout << offspring[i] << " ";
    }
    std::cout << std::endl;
}

Genome ordered_crossover(const Genome &parent_1, const Genome &parent_2, int crossover_start, int crossover_end)
{
    std::vector<int> p1_path = parent_1.path;    // extract path in parents
    std::vector<int> p2_path = parent_2.path;  // delete sentinal value /0

    std::vector<int> offspring(p1_path.begin(), p1_path.begin() +
                                                crossover_end);        // create new path with same len as parents with x in each elem

    offspring.insert(offspring.end(), p2_path.begin() + crossover_end,
                     p2_path.end());  // fill into offspring a part of parent_1

    std::map<int, std::vector<int>> map;

    for (int i = 0; i < offspring.size(); i++)
    {
        map[i] = std::vector<int>();
    }

    for (int i = 0; i < offspring.size(); i++)
    {
        map[offspring[i]].push_back(i);
    }

    std::vector<int> zero_instances;
    std::vector<int> mult_instances;

    for (auto &item: map)
    {
        if (item.second.size() == 0)
        {
            zero_instances.push_back(item.first);
        } else if (item.second.size() > 1)
        {
            mult_instances.push_back(item.first);
        }
    }

    for (int i = 0; i < mult_instances.size(); i++)
    {
        while (map[mult_instances[i]].size() > 1)
        {

            int rand_index = std::experimental::fundamentals_v2::randint(0, (int) map[mult_instances[i]].size() - 1);

            int rand_city = std::experimental::fundamentals_v2::randint(0, (int) zero_instances.size() - 1);

            offspring[map[mult_instances[i]][rand_index]] = zero_instances[rand_city];
            map[mult_instances[i]].erase(map[mult_instances[i]].begin() + rand_index);
            zero_instances.erase(zero_instances.begin() + rand_city);
        }
    }

    float fitness = 1;
    Genome new_genome{offspring, fitness};
    return new_genome;
}

Genome mutation(const Genome &chromosome, int mutation_rate)
{
    std::vector<int> offspring;         // for storing mutated path
    std::vector<int> possible_positions; // for possible index
    for (int i = 0; i < chromosome.path.size(); i++)
    {
        offspring.push_back(chromosome.path[i]);    // copy of path in chromosome
    }

    for (int i = 0; i < offspring.size(); i++)
    {
        possible_positions.push_back(i);            // create indexes
    }

    std::random_device rd;            // rand num form internet
    std::mt19937 gen(rd());            // might nit be correct
    std::uniform_int_distribution<int> dist(0, possible_positions.size() - 1);

    for (int i = 0; i < mutation_rate; i++)
    {
        int position_1 = dist(gen);
        int position_2 = dist(gen);        // just swaps two cities

        std::swap(offspring[position_1], offspring[position_2]);
    }

    float fitness = 1;
    Genome new_offspring{offspring, fitness};
    return new_offspring;
}

void Test()
{
    Genome parent1{{0, 1, 3, 4, 2, 5, 7, 8, 9, 6}, 1};
    Genome parent2{{3, 0, 1, 2, 4, 6, 8, 9, 5, 7}, 1};

    int crossover_start = 0;
    int crossover_end = 2;
    Genome offspring = ordered_crossover(parent1, parent2, crossover_start, crossover_end);

    int mutation_rate = 3;
    Genome mutated_offspring = mutation(offspring, mutation_rate);

    std::cout << "parent1:\t\t";
    P(parent1.path);

    std::cout << "parent2:\t\t";
    P(parent2.path);

    std::cout << "Offspring:\t\t";
    P(offspring.path);

    std::cout << "Mutated Offspring:\t";
    P(mutated_offspring.path);
}

int main()
{
    Test();
    return 0;
}
