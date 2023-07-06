#ifndef TSP_GA_ROULETTEWHEELSELECTION_H
#define TSP_GA_ROULETTEWHEELSELECTION_H

#include "../data-structures/Population.h"

// RouletteWheelSelection class for selecting individuals from a population using roulette wheel selection
class RouletteWheelSelection
{
public:
    explicit RouletteWheelSelection(const Population &population);

    // Get an individual from the population using roulette wheel selection
    const chromosome_t &getIndividual();

private:
    // Reference to the population
    const Population &population;
    
    // Probabilities associated with each individual in the population
    std::vector<double> probabilities;

};

#endif //TSP_GA_ROULETTEWHEELSELECTION_H
