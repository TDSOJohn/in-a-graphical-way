#include <curses.h>

#include "../headers/Screen.hpp"
#include "../headers/Pixel.hpp"
#include "../headers/VertexArray.hpp"


int main()
{
    srand(time(NULL));
    iagw::Screen sc;

    iagw::vi2d size = sc.returnSize();

    for(int i = 0; i < size.x; i++)
    {
        for(int j = 0; j < size.y; j++)
        {
            if((((i-50) * (i-50) / 4) + ((j-25) * (j-25))) < 500)
                sc.printCh(i, j, 5, 5, ' ');
            if(i == 2*j)
                sc.printCh(i, j, 2, 5, ' ');
        }
    }

    iagw::vi2d vs[3] = {{10,10},{27,32},{124,12}};

    iagw::VertexArray v1;
    iagw::VertexArray v2;
    iagw::VertexArray v3;

    v2.move(vs[1]);
    v3.move(vs[2]);

    v3.setColor(3, 2);

    v1.drawYourself();
    v2.drawYourself();
    v3.drawYourself();

    init_color(COLOR_MAGENTA, 700, 0, 700);

    sc.show();

    while(true)
    {

    }

    return 0;
}
