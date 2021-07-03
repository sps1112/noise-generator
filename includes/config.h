#ifndef CONFIG_H
#define CONFIG_H

// Texture Settings
#define TEXTURE_COLUMNS 800
#define TEXTURE_ROWS 600
#define TEXTURE_LOD 1

// Noise Settings
#define RANDOMIZE_SEED 0
#define NOISE_SCALE 100
#define NUMBER_OCTAVES 4
#define PERSISTANCE 0.5f
#define LACUNARITY 2.0f
#define SCALE_FROM_CENTER 1
#define FALLOFF_CURVE 4
#define FALLOFF_SHIFT 5

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
#define DARK_BLUE Colorf(0.1f, 0.2f, 1.0f)
#define OCEAN_BLUE Colorf(0.2f, 0.75f, 1.0f)
#define DARK_YELLOW Colorf(0.95f, 0.95f, 0.1f)
#define LAND_GREEN Colorf(0.1f, 0.95f, 0.1f)
#define DARK_GREEN Colorf(0.1f, 0.65f, 0.1f)
#define LIGHT_BROWN Colorf(0.5f, 0.25f, 0.0f)
#define DARK_BROWN Colorf(0.3f, 0.075f, 0.0f)
#define LIGHT_BLUE Colorf(0.75f, 1.0f, 1.0f)

// Image Settings
#define GAMMA_CORRECTION 0

#endif // CONFIG_H
