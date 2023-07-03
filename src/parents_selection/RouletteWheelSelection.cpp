#include "RouletteWheelSelection.h"

RouletteWheelSelection::RouletteWheelSelection(const Population &population) : population(population)
{
    probabilities.reserve(population.size());
}
