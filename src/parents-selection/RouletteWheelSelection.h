#ifndef TSP_GA_ROULETTEWHEELSELECTION_H
#define TSP_GA_ROULETTEWHEELSELECTION_H

#include "../data-structures/Population.h"

class RouletteWheelSelection
{
public:
    explicit RouletteWheelSelection(const Population &population);
    const chromosome_t &getIndividual();

private:
    const Population &population;
    std::vector<double> probabilities;

};


#endif //TSP_GA_ROULETTEWHEELSELECTION_H
