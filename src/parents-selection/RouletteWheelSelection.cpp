#include <random>
#include <iostream>
#include "RouletteWheelSelection.h"

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
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<> distribution(0., 1.);

    double random_number = distribution(generator);

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
