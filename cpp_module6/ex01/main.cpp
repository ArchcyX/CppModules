#include "./ScalarConvertor.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConvertor::convert(argv[1]);
    else
    {
        std::cout << "Error: Please enter the value" << std::endl;
        std::cout << "Kullanim: ./convert <value>" << std::endl;
    }
    return (0);
}
