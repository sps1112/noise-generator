#ifndef TEXTURE_H
#define TEXTURE_H

#include <config.h>
#include <math_def.h>
#include <iostream>
#include <array>

// Color Data Type for the stb library
using Colori = uint32_t;
// Returns a Colori from (r,g,b) values
Colori get_color(float r, float g, float b)
{
#if GAMMA_CORRECTION
    // Gamma correction
    double gamma = 1 / 2.2;
    r = std::pow(clamp(r), gamma);
    g = std::pow(clamp(g), gamma);
    b = std::pow(clamp(b), gamma);
#endif
    // Convert a valid Colorf to Colori
    return (255 << 24) | ((int)std::floor(b * 255) << 16) | ((int)std::floor(g * 255) << 8) | (int)std::floor(r * 255);
}

// The Texture data type which holds a float for each pixel
using Texture = float *;
// The Image data type which holda a Colori for each pixel
using Image = Colori *;

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

// Returns an image with a given Texture Data
Image get_image(TextureData *texData)
{
    int imgLOD = texData->lod - 1;
    int rows = texData->rows;
    int columns = texData->columns;
    Image img = new Colori[rows * columns];
    for (int i = 0; i < rows; i += 1 + imgLOD)
    {
        for (int j = 0; j < columns; j += 1 + imgLOD)
        {
            int texIndex = texData->get_index(i, j);
            int iEnd = clampi(i + imgLOD, 0, rows - 1);
            int jEnd = clamp(j + imgLOD, 0, columns - 1);
            for (int newI = i; newI <= iEnd; newI++)
            {
                for (int newJ = j; newJ <= jEnd; newJ++)
                {
                    int imgIndex = texData->get_index(newI, newJ);
                    img[imgIndex] = get_color(texData->tex[texIndex], texData->tex[texIndex], texData->tex[texIndex]);
                }
            }
            // img[tex->get_index(i, j)] = 0xFF000000; // black
        }
    }
    return img;
}

Image get_random_image(TextureData *texData)
{
    int imgLOD = texData->lod;
    int rows = texData->rows;
    int columns = texData->columns;
    Image img = new Colori[rows * columns];
    for (int i = 0; i < rows; i += imgLOD)
    {
        for (int j = 0; j < columns; j += imgLOD)
        {
            float colR = get_random_noise();
            float colG = get_random_noise();
            float colB = get_random_noise();
            int iEnd = clampi(i + imgLOD, 0, rows - 1);
            int jEnd = clamp(j + imgLOD, 0, columns - 1);
            for (int newI = i; newI <= iEnd; newI++)
            {
                for (int newJ = j; newJ <= jEnd; newJ++)
                {
                    int imgIndex = texData->get_index(newI, newJ);
                    img[imgIndex] = get_color(colR, colG, colB);
                }
            }
        }
    }
    return img;
}

#endif // TEXTURE_H
