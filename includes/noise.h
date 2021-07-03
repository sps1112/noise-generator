#ifndef NOISE_H
#define NOISE_H

// Header Declarations
#include <iostream>
#include <random>
#include <ctime>

// FLushed Random Val
void flush_value()
{
    float val = rand();
}

// Generates A New Seed Based on Time
void generate_new_seed()
{
    srand(time(0));
    flush_value();
}

// Returns a Random Number b/w 0 and 1
float get_random_noise()
{
    return ((float)rand() / RAND_MAX);
}

#endif // NOISE_H
