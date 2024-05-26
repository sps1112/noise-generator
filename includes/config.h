#ifndef CONFIG_H
#define CONFIG_H

// Texture Settings
#define TEXTURE_COLUMNS 800
#define TEXTURE_ROWS 600
#define TEXTURE_LOD 1

// Noise Settings
#define RANDOMIZE_SEED 0
#define DRAW_PERLIN_NOISE 1
#define NOISE_SCALE 100
#define DRAW_OCTAVES 1
#define NUMBER_OCTAVES 4
#define PERSISTANCE 0.5f
#define LACUNARITY 2.0f
#define SCALE_FROM_CENTER 1
#define DRAW_COLORMAP 1
#define APPLY_FALLOFF 1
#define FALLOFF_CURVE 4
#define FALLOFF_SHIFT 5
#define DRAW_FALLOFF_ONLY 0

// Color Settings
#define COLOR_WHITE Colorf(1.0f)
#define COLOR_BLACK Colorf(0.0f)
#define COLOR_GRAY Colorf(0.3f, 0.59f, 0.11f)
#define COLOR_RED Colorf(1.0f, 0.0f, 0.0f)
#define COLOR_GREEN Colorf(0.0f, 1.0f, 0.0f)
#define COLOR_BLUE Colorf(0.0f, 0.0f, 1.0f)
#define COLOR_YELLOW Colorf(1.0f, 1.0f, 0.0f)
#define COLOR_PURPLE Colorf(1.0f, 0.0f, 1.0f)
#define COLOR_CYAN Colorf(0.0f, 1.0f, 1.0f)
// Biome Colors
#define DARK_BLUE Colorf(0.07f, 0.15f, 0.3f)
#define OCEAN_BLUE Colorf(0.07f, 0.5f, 0.69f)
#define DARK_YELLOW Colorf(0.8f, 0.7f, 0.4f)
#define LAND_GREEN Colorf(0.07f, 0.7f, 0.13f)
#define DARK_GREEN Colorf(0.06f, 0.375f, 0.1f)
#define LIGHT_BROWN Colorf(0.35f, 0.25f, 0.11f)
#define DARK_BROWN Colorf(0.2f, 0.16f, 0.16f)
#define LIGHT_BLUE Colorf(0.80f, 0.9f, 0.9f)

// Map Settings
#define MAP_REGIONS 8
#define BLEND_REGIONS 1
#define BLEND_THRESHOLD 0.85f
#define BLEND_FACTOR 0.65f
#define DRAW_CLOUDS 1
#define CLOUD_THRESHOLD 0.85f

// Image Settings
#define GAMMA_CORRECTION 0

#endif // CONFIG_H
