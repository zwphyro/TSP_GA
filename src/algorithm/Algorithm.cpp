//
// Created by karim on 3/07/23.
//

#include "Algorithm.h"
#include "../parents-selection/RouletteWheelSelection.h"
#include "../mating/mating.h"
#include "../new-generation-selection/NewGenerationSelection.h"
#include<iostream>

Algorithm::Algorithm(const graph_t &graph, int population_size) : graph(graph), population_size(population_size)
{
    mutation_probability = 0.2;
    amount_of_crossover_dots = 2;
    populations_history.emplace_back(getFirstGeneration());
    current_population = populations_history.begin();
    max_population_history_size = 5;

    end_detector = false;
}

Population Algorithm::getFirstGeneration()
{
    std::vector<chromosome_t> generation;
    for (int i = 0; i < population_size; i++)
    {
        generation.emplace_back(graph.size());
        auto &currant_individual = generation.back();

        std::iota(currant_individual.begin(), currant_individual.end(), 0);

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::shuffle(currant_individual.begin(), currant_individual.end(), generator);
    }

    return {generation, graph};
}

const Population &Algorithm::getCurrentPopulation() const
{
    return *current_population;
}

int Algorithm::switchToNextPopulation()
{
    auto next_population = current_population;
    next_population++;
    if (next_population != populations_history.end())
    {
        current_population++;
        return 0;
    }

    if (end_detector)
    {
        return 1;
    }

    RouletteWheelSelection selector(*current_population);
    std::vector<chromosome_t> children;
    children.reserve(population_size);

    Mating mater;
    int crossover_start = 0;
    int crossover_end;

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(0, graph.size() - 1);

    for (int i = 0; i < population_size; i++)
    {
        crossover_end = distribution(generator);
        if (amount_of_crossover_dots == 2)
        {
            crossover_start = distribution(generator);
            if (crossover_start > crossover_end) std::swap(crossover_start, crossover_end);
        }

        auto &first_parent = selector.getIndividual();
        auto &second_parent = selector.getIndividual();
        children.emplace_back(mater.ordered_crossover(first_parent, second_parent, crossover_start, crossover_end));
        children.back() = mater.mutation(children.back(), (int) (mutation_probability * graph.size()));
    }
    Population children_population(children, graph);

    NewGenerationSelection new_generation_selector;

    auto new_individuals = new_generation_selector.createNewGeneration(*current_population, children_population);
    populations_history.emplace_back(new_individuals, graph);
    current_population++;

//    for (int i = 0; i < populations_history.back().size(); i++)
//    {
//        auto &current_chromosome = populations_history.back()[i];
//        for (auto item: current_chromosome)
//        {
//            std::cout << item << ' ';
//        }
//        std::cout << "=> " << populations_history.back().getFitnessValues()[i] << std::endl;
//    }

    if (populations_history.size() > max_population_history_size)
    {
        populations_history.pop_front();
    }

    return 0;
}

int Algorithm::switchToPreviousPopulation()
{
    if (current_population == populations_history.begin())
        return 1;

    current_population--;
    return 0;
}

void Algorithm::switchToLastPopulation()
{

}
