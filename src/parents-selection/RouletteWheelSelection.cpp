#include "RouletteWheelSelection.h"
#include "../randomizer/Randomizer.h"

RouletteWheelSelection::RouletteWheelSelection(const Population &population) : population(population)
{
    probabilities.reserve(population.size());
    const auto &fitness_values = population.getFitnessValues();
    double reverse_fitness_values_sum = 0;
    for (int i = 0; i < population.size(); i++)
    {
        probabilities.emplace_back(reverse_fitness_values_sum);
        reverse_fitness_values_sum += (1. / (double) fitness_values[i]);
    }

    for (auto &item: probabilities)
    {
        item /= reverse_fitness_values_sum;
    }
}

const chromosome_t &RouletteWheelSelection::getIndividual()
{
    Randomizer randomizer;
    double random_number = randomizer.getRandomDouble(0., 1.);

    int left_bound = -1;
    int right_bound = population.size();

    while (right_bound - left_bound > 1)
    {
        int middle = (right_bound + left_bound) / 2;
        if (random_number > probabilities[middle])
        {
            left_bound = middle;
        } else
        {
            right_bound = middle;
        }
    }

    return population[left_bound];
}
