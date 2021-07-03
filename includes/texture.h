#ifndef TEXTURE_H
#define TEXTURE_H

#include <config.h>
#include <math_def.h>
#include <iostream>
#include <array>

// A Color type as (r,g,b)
struct Colorf
{
    float r;
    float g;
    float b;
    Colorf(float a) : r(a), g(a), b(a) {}
    Colorf(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {}
};

// Color Data Type for the stb library
using Colori = uint32_t;
// Returns a Colori from (r,g,b) values
Colori get_color(Colorf col)
{
#if GAMMA_CORRECTION
    // Gamma correction
    float gamma = 1 / 2.2f;
    col.r = std::pow(clamp(col.r), gamma);
    col.g = std::pow(clamp(col.g), gamma);
    col.b = std::pow(clamp(col.b), gamma);
#endif
    // Convert a valid Colorf to Colori
    return (255 << 24) | ((int)std::floor(col.b * 255) << 16) | ((int)std::floor(col.g * 255) << 8) | (int)std::floor(col.r * 255);
}

// The Texture data type which holds a float for each pixel
using Texture = float *;

// The Texture Data struct
struct TextureData
{
    int rows;
    int columns;
    Texture tex;
    int lod;
    // Default Constructor
    TextureData(int rows_, int columns_) : rows(rows_), columns(columns_), lod(TEXTURE_LOD)
    {
        tex = new float[rows * columns];
    }
    // Returns total number of pixels
    int get_length()
    {
        return rows * columns;
    }
    // Returns a pixel index from row number and column number
    int get_index(int rowNumber, int columnNumber)
    {
        return (rowNumber * columns) + columnNumber;
    }
    // Sets the texture value for a given pixel
    void set_value(float val, int index)
    {
        tex[index] = val;
    }
};

#endif // TEXTURE_H
