#include <iostream>
#include "version.hpp"

#include <vector/vector.hpp>

int main(int argc, char const *argv[])
{
    std::cout << "--OK--" << std::endl;

    std::cout << example_VERSION_MAJOR << std::endl;
    std::cout << example_VERSION_MINOR << std::endl;
    std::cout << example_VERSION_PATCH << std::endl;

    gof::Vector v(1, 2, 3);

    std::cout << v.x() << std::endl;
    std::cout << v.y() << std::endl;
    std::cout << v.z() << std::endl;

    return 0;
}
