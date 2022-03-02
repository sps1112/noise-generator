#ifndef MAPGEN_H
#define MAPGEN_H

// Custom Headers
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

// Returns a random image with each pixel a random color
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

// The Map Section Struct for the Color Map
struct MapSection
{
    Colorf col;   // Color of the Section
    float height; // The Height from which section starts
    // Default Constructor
    MapSection(Colorf col_, float height_ = 0.0f) : col(col_)
    {
        height = clamp(height_);
    }
};

// The Default Map Sections for a Color Map
const MapSection mapSections[MAP_REGIONS] = {
    MapSection(DARK_BLUE),
    MapSection(OCEAN_BLUE, 0.05f),
    MapSection(DARK_YELLOW, 0.375f),
    MapSection(LAND_GREEN, 0.4f),
    MapSection(DARK_GREEN, 0.65f),
    MapSection(LIGHT_BROWN, 0.70f),
    MapSection(DARK_BROWN, 0.85f),
    MapSection(LIGHT_BLUE, 0.925f)};

// Gets the Section index from the pixel height
int get_index_from_height(float height)
{
    int n = 0;
    for (int i = 0; i < MAP_REGIONS; i++)
    {
        if (mapSections[i].height > height)
        {
            break;
        }
        n = i;
    }
    return n;
}

// Gets the Section from the pixel height
Colorf get_color_from_sections(float height)
{
    return mapSections[get_index_from_height(height)].col;
}

// Gets Color Map from Noise Map
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
                    float height = texData->tex[texIndex];

                    int index = get_index_from_height(height);
                    Colorf col = mapSections[index].col;
#if BLEND_REGIONS
                    int indexB = index + 1;
                    float h2 = 1.0f;
                    Colorf col2(1.0f);
                    if (indexB < MAP_REGIONS)
                    {
                        h2 = mapSections[indexB].height;
                        col2 = mapSections[indexB].col;
                    }

                    float off = inverse_lerp(height, mapSections[index].height, h2);
                    if (off > BLEND_THRESHOLD)
                    {
                        Colorf mixCol = col_lerp(col, col2, off);
                        col = col_lerp(col, mixCol, BLEND_FACTOR);
                    }
#endif
                    int imgIndex = texData->get_index(newI, newJ);
                    img[imgIndex] = get_color(col);
                }
            }
        }
    }
    return img;
}

#endif // MAPGEN_H
