//
// Created by karim on 3/07/23.
//

#ifndef TSP_GA_ALGORITHM_H
#define TSP_GA_ALGORITHM_H

#include "../data-structures/PopulationList.h"
#include "../ui/controller/Settings.h"
#include <QObject>

/*
 * Class that implements genetic algorithm interface
 */
class Algorithm : public QObject
{
Q_OBJECT
signals:
    void changePlot();

public:
    Algorithm(const graph_t &graph, Settings settings);
    const Population &getCurrentPopulation() const;
    int switchToNextPopulation();
    int switchToPreviousPopulation();
    void switchToLastPopulation();

    std::size_t getAllPopulationsAmount() const;
    const std::vector<long> &getSolutionsHistory() const;

    const graph_t &graph;
    void generateNextPopulation();

private:
    int population_size;
    double mutation_probability;
    int amount_of_crossover_dots;
    int max_population_history_size;
    int mutation_type;

    int equivalent_solutions_amount;
    bool end_detector;

    std::vector<long> solutions_history;
    std::list<Population>::iterator current_population;
    population_list_t populations_history;

    void generateFirstPopulation();
};


#endif //TSP_GA_ALGORITHM_H
