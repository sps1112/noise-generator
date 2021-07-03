#ifndef TEXTURE_H
#define TEXTURE_H

#include <config.h>
#include <iostream>
#include <array>

// Color Data Type for the stb library
using Colori = uint32_t;
// Returns a Colori from (r,g,b) values
Colori get_color(float r, float g, float b)
{
#if GAMMACORRETION
    // Gamma correction
    double gamma = 1 / 2.2;
    double r = std::pow(r, gamma);
    double g = std::pow(g, gamma);
    double b = std::pow(b, gamma);
#endif
    // Convert a valid Colorf to Colori
    return (255 << 24) | ((int)std::floor(b * 255) << 16) | ((int)std::floor(g * 255) << 8) | (int)std::floor(r * 255);
}

// The Texture data type which holds a float for each pixel
using Texture = std::array<float, TEXTURE_COLUMNS * TEXTURE_ROWS>;
// The Image data type which holda a Colori for each pixel
using Image = std::array<Colori, TEXTURE_COLUMNS * TEXTURE_ROWS>;

// The Texture Data struct
struct TextureData
{
    int rows;
    int columns;
    Texture tex;
    // Default Constructor
    TextureData(int rows_, int columns_) : rows(rows_), columns(columns_) {}
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
    Image img;
    for (int i = 0; i < texData->rows; i++)
    {
        for (int j = 0; j < texData->columns; j++)
        {
            int index = texData->get_index(i, j);
            // img[tex->get_index(i, j)] = 0xFF000000; // black
            img[index] = get_color(texData->tex[index], texData->tex[index], texData->tex[index]);
        }
    }
    return img;
}

#endif // TEXTURE_H
