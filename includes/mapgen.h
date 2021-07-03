#ifndef MAPGEN_H
#define MAPGEN_H

#include <texture.h>
#include <config.h>

// The Image data type which holds a Colori for each pixel
using Image = Colori *;

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
                    Colorf col(texData->tex[texIndex]);
                    img[imgIndex] = get_color(col);
                }
            }
            // img[tex->get_index(i, j)] = 0xFF000000; // black
        }
    }
    return img;
}

// Returns a random image
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
            Colorf col(get_random_noise(), get_random_noise(), get_random_noise());
            int iEnd = clampi(i + imgLOD, 0, rows - 1);
            int jEnd = clamp(j + imgLOD, 0, columns - 1);
            for (int newI = i; newI <= iEnd; newI++)
            {
                for (int newJ = j; newJ <= jEnd; newJ++)
                {
                    int imgIndex = texData->get_index(newI, newJ);
                    img[imgIndex] = get_color(col);
                }
            }
        }
    }
    return img;
}

struct MapSection
{
    Colorf col;
    float height;
    MapSection(Colorf col_, float height_ = 0.0f) : col(col_)
    {
        height = clamp(height_);
    }
};

MapSection mapSections[8] = {
    MapSection(DARK_BLUE),
    MapSection(OCEAN_BLUE, 0.05f),
    MapSection(DARK_YELLOW, 0.375f),
    MapSection(LAND_GREEN, 0.4f),
    MapSection(DARK_GREEN, 0.65f),
    MapSection(LIGHT_BROWN, 0.70f),
    MapSection(DARK_BROWN, 0.85f),
    MapSection(LIGHT_BLUE, 0.925f)};

Colorf get_color_from_sections(float height)
{
    Colorf col(0.0f);
    for (int i = 0; i < 8; i++)
    {
        if (mapSections[i].height > height)
        {
            break;
        }
        col = mapSections[i].col;
    }
    return col;
}

Image get_colormap(TextureData *texData)
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
                    float height = texData->tex[texIndex];
                    Colorf col = get_color_from_sections(height);
                    img[imgIndex] = get_color(col);
                }
            }
        }
    }
    return img;
}

#endif // MAPGEN_H
