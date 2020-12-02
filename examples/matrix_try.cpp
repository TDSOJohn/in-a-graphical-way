#include <iostream>

#include "../headers/Transform.hpp"


int main()
{
    iagw::Transform m1(1.f);
    iagw::Transform m2(m1);

    iagw::vf2d v1(3.f, 4.f);

    iagw::Transform ident(1, 0, 0, 0, 1, 0, 0, 0, 1);

    std::cout << (m1 == m2) << "\t" << (m1 == ident) << std::endl;

    for(int i = 0; i < 9; i++)
    {
        if(!(i % 3))
            std::cout << std::endl;
        std::cout << (m2.getMatrix())[i] << "\t";
    }
    std::cout << std::endl;

    v1 = ident * v1;

    std::cout << v1.x << "\t" << v1.y << std::endl;

    for(int i = 0; i < 9; i++)
    {
        if(!(i % 3))
            std::cout << std::endl;
        std::cout << (m1.getMatrix())[i] << "\t";
    }
    std::cout << std::endl;

    m1 *= m2;

    for(int i = 0; i < 9; i++)
    {
        if(!(i % 3))
            std::cout << std::endl;
        std::cout << (m1.getMatrix())[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}
