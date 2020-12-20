#include <thread>
#include <chrono>
#include <deque>

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

    iagw::vf2d new_orig;
    iagw::vf2d v_1_speed = { 1.f, 0.f };

    iagw::Rectf bounds;

    int counter = 0;

    while(true)
    {
        v_1.rotate(1.f);

        bounds = v_1.getGlobalBounds();
/*
        if((bounds.x <= 0) || (bounds.x + bounds.width >= sc_size.x))
            v_1_speed.x *= -1;
        if((bounds.y <= 0) || (bounds.y + bounds.height >= sc_size.y))
            v_1_speed.y *= -1;
*/
//        v_1.move(v_1_speed);

        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        sc.clear();

        v_1.drawYourself();

        counter++;
        counter = counter%60;
    }

    return 0;
}
