#include <iostream>

#include "../headers/VertexArray.hpp"

void print_matrix(const float* m_in)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            std::cout << m_in[i * 3 + j] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));

    iagw::VertexArray v1;

    std::cout   << v1.getGlobalBounds().x
                << "\t" << v1.getGlobalBounds().y << "\n\n";
    std::cout   << v1.getGlobalBounds().width
                << "\t" << v1.getGlobalBounds().height << "\n\n";

    print_matrix(v1.getTransform().getMatrix());

    v1.move(3, 3);
    print_matrix(v1.getTransform().getMatrix());

    return 0;
}
