// Custom Headers
#include <noise.h>
#include <stb_image_write.h>
#include <texture.h>
// Standard Headers
#include <iostream>

int main()
{
    generate_new_seed();

    std::cout << "Generating Texture..." << std::endl;
    TextureData texData(TEXTURE_ROWS, TEXTURE_COLUMNS);
    for (int i = 0; i < texData.rows; i++)
    {
        for (int j = 0; j < texData.columns; j++)
        {
            texData.set_value(get_random_noise(), texData.get_index(i, j));
        }
    }

    std::cout << "Generating Image..." << std::endl;
    Image img = new Colori[texData.rows * texData.columns];
    img = get_image(&(texData));

    stbi_write_png("out.png", texData.columns, texData.rows, 4, (void *)(img), texData.columns * sizeof(Colori));
}
