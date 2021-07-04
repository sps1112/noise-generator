// Custom Headers
#include <noise.h>
#include <stb_image_write.h>
#include <texture.h>
#include <mapgen.h>

// Standard Headers
#include <iostream>

int main()
{
#if RANDOMIZE_SEED
    generate_new_seed();
#endif

    std::cout << "Generating Texture..." << std::endl;
    TextureData texData(TEXTURE_ROWS, TEXTURE_COLUMNS);
#if !DRAW_FALLOFF_ONLY
#if DRAW_PERLIN_NOISE
#if DRAW_OCTAVES
    Texture noiseMap = get_noisemap(texData.rows, texData.columns, NOISE_SCALE, NUMBER_OCTAVES, PERSISTANCE, LACUNARITY);
#else
    Texture noiseMap = get_noisemap(texData.rows, texData.columns, NOISE_SCALE);
#endif
#else
    Texture noiseMap = get_noisemap(texData.rows, texData.columns);
#endif

#if APPLY_FALLOFF
    Texture falloffMap = get_falloffmap(texData.rows, texData.columns, FALLOFF_CURVE, FALLOFF_SHIFT);
    texData.tex = subtract_maps(noiseMap, falloffMap, texData.rows, texData.columns);
#else
    texData.tex = noiseMap;
#endif
#else
    Texture falloffMap = get_falloffmap(texData.rows, texData.columns, FALLOFF_CURVE, FALLOFF_SHIFT);
    texData.tex = falloffMap;
#endif

    std::cout << "Generating Image..." << std::endl;
    Image img = new Colori[texData.rows * texData.columns];
#if DRAW_COLORMAP
    img = get_colormap(&(texData));
#else
    img = get_image(&(texData));
#endif

    stbi_write_png("out.png", texData.columns, texData.rows, 4, (void *)(img), texData.columns * sizeof(Colori));
    std::cout << "Finish!!!" << std::endl;
}
