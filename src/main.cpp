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
    Texture noiseMap = get_noisemap(texData.rows, texData.columns, NOISE_SCALE, NUMBER_OCTAVES, PERSISTANCE, LACUNARITY);
    Texture falloffMap = get_falloffmap(texData.rows, texData.columns, FALLOFF_CURVE, FALLOFF_SHIFT);
    texData.tex = subtract_maps(noiseMap, falloffMap, texData.rows, texData.columns);
    // texData.tex = falloffMap;

    std::cout << "Generating Image..." << std::endl;
    Image img = new Colori[texData.rows * texData.columns];
    // img = get_image(&(texData));
    img = get_colormap(&(texData));

    stbi_write_png("out.png", texData.columns, texData.rows, 4, (void *)(img), texData.columns * sizeof(Colori));
    std::cout << "Finish!!!" << std::endl;
}
