#ifndef NOISE_H
#define NOISE_H

#include <math_def.h>

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

float get_perlin_noise(float x, float y)
{
    return 1.0f;
}

enum NOISE_TYPE
{
    RANDOM_NOISE,
    PERLIN_NOISE,
};

float *get_noisemap(int rows, int columns, NOISE_TYPE type = PERLIN_NOISE, float scale = 1.0f)
{
    float *noiseMap = new float[rows * columns];
    scale = floor(scale, 0);
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            float noiseVal = 0.0f;
            float sampleX = x / scale;
            float sampleY = y / scale;
            switch (type)
            {
            case RANDOM_NOISE:
                noiseVal = get_random_noise();
                break;
            case PERLIN_NOISE:
                noiseVal = get_perlin_noise(sampleX, sampleY);
                break;
            default:
                break;
            }
            noiseMap[(y * columns) + x] = noiseVal;
        }
    }
    return noiseMap;
}
#endif // NOISE_H
