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

    iagw::vf2d arr_xy[5] = {{20.f, 20.f},
                            {40.f, 20.f},
                            {40.f, 40.f},
                            {20.f, 40.f},
                            {20.f, 20.f}};

    iagw::VertexArray v_1(arr_xy, 5);
    v_1.setColor(4, 0);
    v_1.setOrigin(30.f, 30.f);

    int counter = 0;
    while(true)
    {
        v_1.rotate(1.f);

        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        sc.clear();

        v_1.drawYourself();
        counter++;
        counter = counter%60;
    }

    return 0;
}
