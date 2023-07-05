#ifndef TSP_GA_MATING_H
#define TSP_GA_MATING_H

#include "../data-structures/Chromosome.h"
#include "../data-structures/Population.h"

class Mating
{
public:
    Mating(int chromosome_size, int amount_of_crossover_dots, double mutation_probability);
    std::vector<chromosome_t> getChildren(const Population &population);

private:
    chromosome_t
    ordered_crossover(const chromosome_t &first_parent, const chromosome_t &second_parent, int crossover_start,
                      int crossover_end);

    chromosome_t mutation(chromosome_t &chromosome, int mutation_rate);
    chromosome_t mutation_switch(chromosome_t &chromosome, int mutation_rate);

    int chromosome_size;
    int amount_of_crossover_dots;
    double mutation_probability;

};

#endif //TSP_GA_MATING_H
