#include <curses.h>

#include "../headers/Screen.hpp"
#include "../headers/Pixel.hpp"
#include "../headers/VertexArray.hpp"


int main()
{
    srand(time(NULL));
    iagw::Screen sc;

    iagw::vi2d sc_size = sc.returnSize();

    int8_t size = 6;
    iagw::vf2d vs[size];

    for(int i = 0; i < size; i++)
    {
        vs[i] = { rand()%sc_size.x, rand()%sc_size.y };
    }

    iagw::VertexArray v1(vs, size);
    iagw::VertexArray v2;
    iagw::VertexArray v3;

    v2.move(27, 12);
    v3.move(74, 12);

    v1.setColor(6, 0);
    v3.setColor(3, 2);

    v1.drawYourself();
    v2.drawYourself();
    v3.drawYourself();

    sc.show();

    while(true)
    {

    }

    return 0;
}
