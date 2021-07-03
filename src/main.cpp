// Custom Headers
#include <noise.h>
// Standard Headers
#include <iostream>

int main()
{
    generate_new_seed();
    std::cout << get_random_noise() << std::endl;
}