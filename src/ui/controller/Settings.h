//
// Created by Маргарита  on 03.07.2023.
//

#ifndef TSP_GA_SETTINGS_H
#define TSP_GA_SETTINGS_H

#include<iostream>
/*
 * mutation:
 * standart = 1
 * reverse = 2
 * mixed = 3
 * */
struct Settings
{
    double probability = 0.2;
    int count_crossover = 2;
    int population_size = 1;
    int mutation = 3;

};

#endif //TSP_GA_SETTINGS_H
