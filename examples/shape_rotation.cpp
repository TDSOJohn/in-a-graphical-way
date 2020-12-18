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

    iagw::vf2d arr_xy[2] = {{20.f, 20.f},
                            {40.f, 20.f}};/*,
                            {40.f, 40.f},
                            {20.f, 40.f},
                            {20.f, 20.f}};
*/
    iagw::vf2d arr_xy_2[5] = {{40.f, 30.f},
                            {55.f, 30.f},
                            {55.f, 40.f},
                            {18.f, 40.f},
                            {40.f, 30.f}};

    iagw::VertexArray v_1(arr_xy, 2);
    iagw::VertexArray v_2(arr_xy_2, 5);

    v_1.setColor(4, 0);
    v_1.setOrigin(20.f, 20.f);

    v_2.setColor(3, 0);
    v_2.setOrigin(60.f, 30.f);

    iagw::vf2d new_orig;

    int counter = 0;
    while(true)
    {
        v_1.rotate(1.f);
        v_2.rotate(-1.f);

/*        v_1.move(1.f, 0.f);
        new_orig = v_1.getOrigin();
        new_orig += {1.f, 0.f};
        v_1.setOrigin(new_orig);
*/
        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        sc.clear();

        v_1.drawYourself();
        v_2.drawYourself();

        counter++;
        counter = counter%60;
    }

    return 0;
}
