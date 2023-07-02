#ifndef TSP_GA_POPULATIONLIST_H
#define TSP_GA_POPULATIONLIST_H

#include <list>
#include "Population.h"

/*
 * Population list is required to easily navigate between different generations of populations
 */
typedef std::list<Population> population_list_t;

#endif //TSP_GA_POPULATIONLIST_H
