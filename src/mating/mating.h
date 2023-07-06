#ifndef TSP_GA_MATING_H
#define TSP_GA_MATING_H

#include "../data-structures/Chromosome.h"
#include "../data-structures/Population.h"

/*
Mating class for performing genetic operations in a Genetic Algorithm
*/
class Mating
{
public:
    // Constructor
    Mating(int chromosome_size, int amount_of_crossover_dots, double mutation_probability);

    // Generate children from the population using crossover and mutation
    std::vector<chromosome_t> getChildren(const Population &population);

    // Generate mutated individuals from the population
    std::vector<chromosome_t> getMutated(const Population &population);

private:
    // Perform ordered crossover on two parent chromosomes
    chromosome_t
    ordered_crossover(const chromosome_t &first_parent, const chromosome_t &second_parent, int crossover_start,
                      int crossover_end);

    // Perform mutation on a chromosome by swapping genes
    void mutation(chromosome_t &chromosome, int mutation_rate);

    // Perform mutation on a chromosome by reversing a segment of genes
    void mutationSwitch(chromosome_t &chromosome, int mutation_rate);

    int chromosome_size;                // Size of the chromosome
    int amount_of_crossover_dots;        // Number of crossover points
    double mutation_probability;        // Probability of mutation
};

#endif //TSP_GA_MATING_H

