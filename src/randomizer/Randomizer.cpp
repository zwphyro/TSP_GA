//
// Created by karim on 5/07/23.
//

#include "Randomizer.h"
#include "random"


/*
Function to generate a random integer within a given range.
*/
int Randomizer::getRandomInt(int left_bound, int right_bound)
{
    // Initialize random device to obtain a random seed.
    std::random_device rd;
    // Create a Mersenne Twister random number engine and seed it with the random device.
    std::mt19937 gen(rd());
    // Create a uniform integer distribution using the given range.
    std::uniform_int_distribution<int> distribution_int(left_bound, right_bound);
    // Generate a random int within the specified range.
    int random_number = distribution_int(gen);
    return random_number;
}


/*
Function to generate a random double within a given range.
*/
double Randomizer::getRandomDouble(double left_bound, double right_bound)
{
    // Initialize random device to obtain a random seed.
    std::random_device rd;
    // Create a Mersenne Twister random number engine and seed it with the random device.
    std::mt19937 gen(rd());
    // Create a uniform real distribution using the given range.
    std::uniform_real_distribution<double> distribution_double(left_bound, right_bound);
    // Generate a random double within the specified range.
    double random_number = distribution_double(gen);
    return random_number;
}
