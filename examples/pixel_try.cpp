#include <thread>
#include <chrono>
#include <deque>

#include <curses.h>

#include "../headers/Screen.hpp"
#include "../headers/VertexArray.hpp"


int main()
{
    iagw::Screen sc;
    iagw::vi2d sc_size = sc.returnSize();

    iagw::vf2d arr_xy[2] = {{0.f, 0.f}, {10.f, 10.f}};


    iagw::VertexArray v_1(arr_xy, 2);
    v_1.setColor(4, 0);

    v_1.setOrigin(10.f, 10.f);

    int counter = 0;
    while(true)
    {
        printw("%d", counter);

        v_1.drawYourself();
        v_1.rotate(1.f);

        sc.show();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        sc.clear();

        counter++;
        counter = counter%60;
    }

    return 0;
}
