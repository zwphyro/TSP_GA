#ifndef TSP_GA_MATING_H
#define TSP_GA_MATING_H

#include "../data-structures/Chromosome.h"

class Mating {
public:
    chromosome_t ordered_crossover(const chromosome_t &parent_1, const chromosome_t &parent_2, int crossover_start,
                                   int crossover_end);

    chromosome_t mutation(const chromosome_t &chromosome, int mutation_rate);
};


#endif //TSP_GA_MATING_H
