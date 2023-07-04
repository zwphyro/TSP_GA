//
// Created by karim on 3/07/23.
//

#ifndef TSP_GA_NEWGENERATIONSELECTION_H
#define TSP_GA_NEWGENERATIONSELECTION_H

#include "../data-structures/Chromosome.h"
#include "../data-structures/Population.h"
#include<algorithm>

/*
 * Class that selects individuals for the next generation
 */
class NewGenerationSelection
{
public:
    std::vector<chromosome_t> createNewGeneration(const Population &left, const Population &right);
};


#endif //TSP_GA_NEWGENERATIONSELECTION_H
