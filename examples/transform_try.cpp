#include <iostream>
#include <cmath>

#include "../headers/VertexArray.hpp"


int main()
{
    srand(time(NULL));


    iagw::vf2d vec1[2] = {{0, 0}, {2, 3}};
    iagw::VertexArray v1(vec1, 2);

    v1.printData();

    std::cout << "move(3, 3)\n";
    v1.move(3, 3);

    v1.printData();

    std::cout << "rotate(45)\n";
    v1.rotate(45);
    v1.printData();

    std::cout << "rotate(45)\n";
    v1.rotate(45);
    v1.printData();

    return 0;
}
