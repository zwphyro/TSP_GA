//
// Created by karim on 3/07/23.
//

#include <iostream>
#include "NewGenerationSelection.h"

/*
 * Method that selects the best individuals from ancestral and descendant populations
 */
std::vector<chromosome_t>
NewGenerationSelection::createNewGeneration(const Population &ancestors, const Population &descendants)
{
    std::vector<std::pair<chromosome_t, long>> all_individuals;

    all_individuals.reserve(ancestors.size() + descendants.size());
    for (int i = 0; i < ancestors.size(); i++)
    {
        all_individuals.emplace_back(ancestors.getIndividuals()[i], ancestors.getFitnessValues()[i]);
    }
    for (int i = 0; i < descendants.size(); i++)
    {
        all_individuals.emplace_back(descendants.getIndividuals()[i], descendants.getFitnessValues()[i]);
    }

    auto compare = [](const std::pair<chromosome_t, long> &left, const std::pair<chromosome_t, long> &right)
    {
        return left.second < right.second;
    };
    std::sort(all_individuals.begin(), all_individuals.end(), compare);

    std::vector<chromosome_t> new_population;
    new_population.reserve(ancestors.size());
    for (int i = 0; i < ancestors.size(); i++)
    {
        new_population.emplace_back(all_individuals[i].first);
    }

    return new_population;
}
