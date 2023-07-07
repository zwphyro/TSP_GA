//
// Created by karim on 3/07/23.
//

#include "Algorithm.h"
#include "../mating/mating.h"
#include "../new-generation-selection/NewGenerationSelection.h"
#include <random>


/*
 * Constructor of the algorithm class, initializes the proles and creates the first population
 */
Algorithm::Algorithm(const graph_t &graph, Settings settings) : graph(graph)
{
    population_size = settings.population_size * graph.size();
    mutation_probability = settings.probability;
    amount_of_crossover_dots = settings.count_crossover;
    max_population_history_size = 20;
    mutation_type = settings.mutation;

    equivalent_solutions_amount = 0;
    end_detector = false;

    generateFirstPopulation();
    current_population = populations_history.begin();
    solutions_history.emplace_back((*current_population).getBestIndividual().second);
}

/*
 * Method creating the first population to start the algorithm
 */
void Algorithm::generateFirstPopulation()
{
    std::vector<chromosome_t> individuals;
    for (int i = 0; i < population_size; i++)
    {
        individuals.emplace_back(graph.size());
        auto &currant_individual = individuals.back();

        std::iota(currant_individual.begin(), currant_individual.end(), 0);

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::shuffle(currant_individual.begin(), currant_individual.end(), generator);
    }

    populations_history.emplace_back(individuals, graph);
}

/*
 * Returns a reference to the current population
 */
const Population &Algorithm::getCurrentPopulation() const
{
    return *current_population;
}

/*
 * Changes the current population to the next population if possible, otherwise it creates the next population
 * If the algorithm has completed its work and cannot create the next population, it returns 1
 */
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

    generateNextPopulation();

    current_population++;
    return 0;
}

/*
 * Changes the current population to the next population
 * If the current population is the last in the list, it returns 1
 */
int Algorithm::switchToPreviousPopulation()
{
    if (current_population == populations_history.begin())
    {
        return 1;
    }

    current_population--;
    return 0;
}

/*
 * Runs the algorithm until the stop condition is met, changes the current population to the last one received
 */
void Algorithm::switchToLastPopulation()
{
    while (!end_detector)
    {
        generateNextPopulation();
        switchToNextPopulation();
    }
}

void Algorithm::generateNextPopulation()
{
    auto &last_population = populations_history.back();
    Mating mater(graph.size(), amount_of_crossover_dots, mutation_probability);
    std::vector<chromosome_t> children_individuals;
    std::vector<chromosome_t> mutated_individuals = mater.getMutated(last_population);
    switch (mutation_type)
    {
        case 1:
            children_individuals = mater.getChildren(last_population);
            break;
        case 2:
            mutated_individuals = mater.getMutated(last_population);
            break;
        case 3:
            children_individuals = mater.getChildren(last_population);
            mutated_individuals = mater.getMutated(last_population);
            break;
    }
    children_individuals.insert(children_individuals.end(), mutated_individuals.begin(), mutated_individuals.end());
    Population children_population(children_individuals, graph);

    NewGenerationSelection new_generation_selector;
    auto new_individuals = new_generation_selector.createNewGeneration(last_population, children_population);

    populations_history.emplace_back(new_individuals, graph);
    solutions_history.emplace_back(populations_history.back().getBestIndividual().second);
    if (populations_history.size() > max_population_history_size)
    {
        populations_history.pop_front();
    }

    if (last_population.getBestIndividual().second == populations_history.back().getBestIndividual().second)
    {
        equivalent_solutions_amount++;
    } else
    {
        equivalent_solutions_amount = 0;
    }

    if (solutions_history.size() * 3 < equivalent_solutions_amount * 4)
    {
        end_detector = true;
    }
    emit(changePlot());
}

std::size_t Algorithm::getAllPopulationsAmount() const
{
    return solutions_history.size();
}

const std::vector<long> &Algorithm::getSolutionsHistory() const
{
    return solutions_history;
}

