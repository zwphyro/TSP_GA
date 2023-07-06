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
    new_population.emplace_back(all_individuals[0].first);
    int previous_added_index = 0;
    int next_index = 1;
    std::vector<int> unused_indexes;
    while (new_population.size() < ancestors.size() && next_index < all_individuals.size())
    {
        if (all_individuals[previous_added_index].second != all_individuals[next_index].second)
        {
            new_population.emplace_back(all_individuals[next_index].first);
            previous_added_index = next_index;
        } else
        {
            unused_indexes.emplace_back(next_index);
        }
        next_index++;
    }

    int difference = ancestors.size() - new_population.size();
    for (int i = 0; i < difference; i++)
    {
        new_population.emplace_back(all_individuals[unused_indexes[i]].first);
    }

    return new_population;
}
