//
// Created by karim on 3/07/23.
//

#include <iostream>
#include "NewGenerationSelection.h"


std::vector<chromosome_t> NewGenerationSelection::createNewGeneration(Population ancestors, Population descendants)
{

    std::vector<std::pair<chromosome_t, long>> new_generation;


    new_generation.reserve(ancestors.size());
    for (int i = 0; i < ancestors.size(); i++)
    {
        new_generation.emplace_back(ancestors.getIndividuals()[i], ancestors.getFitnessValues()[i]);
    }
    for (int i = 0; i < descendants.size(); i++)
    {
        new_generation.emplace_back(descendants.getIndividuals()[i], descendants.getFitnessValues()[i]);
    }

    auto comparePairs = [](const std::pair<chromosome_t, long> &p1, const std::pair<chromosome_t, long> &p2)
    {
        return p1.second < p2.second;
    };
    std::sort(new_generation.begin(), new_generation.end(), comparePairs);

    std::vector<chromosome_t> new_population;

    for (int i = 0; i < ancestors.size(); i++)
    {
        new_population.emplace_back(new_generation[i].first);
    }

    return new_population;
}
