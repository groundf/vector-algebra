#include <iostream>
#include "version.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "--OK--" << std::endl;

    std::cout << example_VERSION_MAJOR << std::endl;
    std::cout << example_VERSION_MINOR << std::endl;
    std::cout << example_VERSION_PATCH << std::endl;

    return 0;
}
