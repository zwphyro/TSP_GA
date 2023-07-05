//
// Created by karim on 3/07/23.
//

#include "Algorithm.h"
#include "../mating/mating.h"
#include "../parents-selection/RouletteWheelSelection.h"
#include "../new-generation-selection/NewGenerationSelection.h"
#include <random>
#include "../randomizer/Randomizer.h"


/*
 * Constructor of the algorithm class, initializes the proles and creates the first population
 */
Algorithm::Algorithm(const graph_t &graph, int population_size) : graph(graph)
{
    this->population_size = population_size;
    mutation_probability = 0.2;
    amount_of_crossover_dots = 2;
    max_population_history_size = 5;
    end_detector = false;

    generateFirstPopulation();
    current_population = populations_history.begin();
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

    // put this part in a separate method of the Mating class
    RouletteWheelSelection selector(*current_population);
    std::vector<chromosome_t> children;
    children.reserve(population_size);

    Mating mater;
    int crossover_start = 0;
    int crossover_end;

    Randomizer randomizer;

    for (int i = 0; i < population_size; i++)
    {
        crossover_end = randomizer.getRandomInt(0, graph.size() - 1);
        if (amount_of_crossover_dots == 2)
        {
            crossover_start = randomizer.getRandomInt(0, graph.size() - 1);
            if (crossover_start > crossover_end) std::swap(crossover_start, crossover_end);
        }

        auto &first_parent = selector.getIndividual();
        auto &second_parent = selector.getIndividual();
        children.emplace_back(mater.ordered_crossover(first_parent, second_parent, crossover_start, crossover_end));
        children.back() = mater.mutation(children.back(), (int) (mutation_probability * graph.size()));
    }
    Population children_population(children, graph);
    // end

    NewGenerationSelection new_generation_selector;
    auto new_individuals = new_generation_selector.createNewGeneration(*current_population, children_population);

    populations_history.emplace_back(new_individuals, graph);
    current_population++;
    if (populations_history.size() > max_population_history_size)
    {
        populations_history.pop_front();
    }

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

}
