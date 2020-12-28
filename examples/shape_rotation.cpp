#include <cmath>
#include <thread>
#include <chrono>
#include <deque>

#include "../headers/Screen.hpp"
#include "../headers/VertexArray.hpp"


int main()
{
    iagw::Screen sc;
    iagw::vi2d sc_size = sc.returnSize();

    iagw::vf2d arr_xy[5] = {{0.f, 0.f},
                            {20.f, 0.f},
                            {20.f, 20.f},
                            {0.f, 20.f},
                            {0.f, 0.f}};

    iagw::VertexArray v_1(arr_xy, 5);

    v_1.setColor(4, 0);
    v_1.setOrigin(10.f, 10.f);
    v_1.move(20.f, 20.f);

    iagw::vf2d new_orig;
    iagw::vf2d v_1_speed = { 1.f, 1.f };
    float rotation_speed = 2.f;

    iagw::Rectf bounds;

    int counter = 0;

    while(true)
    {
        v_1.rotate(rotation_speed);

        bounds = v_1.getGlobalBounds();

        if(bounds.x <= 0)
            v_1_speed.x = std::fabs(v_1_speed.x);
        else if(bounds.x + bounds.width >= (sc_size.x - 2))
            v_1_speed.x = std::fabs(v_1_speed.x) * (-1);

        if(bounds.y <= 0)
            v_1_speed.y = std::fabs(v_1_speed.y);
        else if(bounds.y + bounds.height >= (sc_size.y - 1))
         v_1_speed.y = std::fabs(v_1_speed.y) * (-1);

        v_1.move(v_1_speed);

        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        sc.clear();

        v_1.drawYourself();

        counter++;
        counter = counter%60;
    }

    return 0;
}
