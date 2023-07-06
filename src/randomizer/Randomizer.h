//
// Created by karim on 5/07/23.
//

#ifndef TSP_GA_RANDOMIZER_H
#define TSP_GA_RANDOMIZER_H


// Class declaration for Randomizer
class Randomizer
{
public:
    // Function to generate a random integer within a given range.
    int getRandomInt(int left_bound, int right_bound);

    // Function to generate a random double within a given range.
    double getRandomDouble(double left_bound, double right_bound);
};

#endif //TSP_GA_RANDOMIZER_H
