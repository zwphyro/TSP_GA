//
// Created by karim on 5/07/23.
//

#include "Randomizer.h"
#include "random"

int Randomizer::getRandomInt(int left_bound, int right_bound)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution_int(left_bound, right_bound);
    int random_number = distribution_int(gen);
    return random_number;
}

double Randomizer::getRandomDouble(double left_bound, double right_bound)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution_double(left_bound, right_bound);
    double random_number = distribution_double(gen);

    return random_number;
}
