#include "RouletteWheelSelection.h"
#include "../randomizer/Randomizer.h"

/*
Constructor for RouletteWheelSelection class
Initializes the probabilities vector based on the fitness values of the population
*/
RouletteWheelSelection::RouletteWheelSelection(const Population &population) : population(population)
{
    // Reserve memory for the probabilities vector based on the size of the population
    probabilities.reserve(population.size());

// Get the fitness values of the population
    const auto &fitness_values = population.getFitnessValues();

// Initialize the sum of reverse fitness values to 0
    double reverse_fitness_values_sum = 0;

// Calculate reverse fitness values and accumulate the sum
    for (int i = 0; i < population.size(); i++)
    {
        // Add the current sum of reverse fitness values to the probabilities vector
        probabilities.emplace_back(reverse_fitness_values_sum);

        // Calculate the reverse fitness value for the current individual
        reverse_fitness_values_sum += (1. / (double) fitness_values[i]);
    }

// Normalize the probabilities by dividing each value by the sum of reverse fitness values
    for (auto &item: probabilities)
    {
        item /= reverse_fitness_values_sum;
    }
}


/*
Retrieves an individual from the population using roulette wheel selection
*/
const chromosome_t &RouletteWheelSelection::getIndividual()
{
    Randomizer randomizer;

// Generate a random number between 0 and 1
    double random_number = randomizer.getRandomDouble(0., 1.);

    int left_bound = -1;
    int right_bound = population.size();

// Perform binary search to find the individual in the population
    while (right_bound - left_bound > 1)
    {
        int middle = (right_bound + left_bound) / 2;

        if (random_number > probabilities[middle])
        {
            // Update the left bound if the random number is greater than the probability at the middle index
            left_bound = middle;
        } else
        {
            // Update the right bound if the random number is less than or equal to the probability at the middle index
            right_bound = middle;
        }
    }

// Return the individual found using the binary search
    return population[left_bound];
}
