#include <thread>
#include <chrono>
#include <deque>

#include <curses.h>

#include "../headers/Screen.hpp"
#include "../headers/Pixel.hpp"
#include "../headers/VertexArray.hpp"

struct Moving
{
    iagw::VertexArray   m_v;

    float               m_r;
    float               m_vx;
    float               m_vy;
};

int main()
{
    srand(time(NULL));
    iagw::Screen sc;

    std::deque<Moving> lines_arr;

    iagw::vi2d sc_size = sc.returnSize();

    const int8_t size = 6;
    iagw::vf2d vs[size];

    for(int i = 0; i < 10; i++)
        lines_arr.push_back({   iagw::VertexArray(),
                                static_cast<float>(rand()%11 - 5) / 10,
                                static_cast<float>(rand()%11 - 5) / 10,
                                static_cast<float>(rand()%11 - 5) / 10});

    int counter = 0;

    while(true)
    {
        if(!(counter%50))
        {
            lines_arr.pop_front();
            for(int i = 0; i < size; i++)
            {
                vs[i] = {   rand()%sc_size.x,
                            rand()%sc_size.y };
            }
            lines_arr.push_back({   iagw::VertexArray(vs, size),
                                    static_cast<float>(rand()%11 - 5) / 10,
                                    static_cast<float>(rand()%11 - 5) / 10,
                                    static_cast<float>(rand()%11 - 5) / 10});

            lines_arr.back().m_v.setColor(rand()%8, 0);
        }
        if(!(counter%20))
        {
            lines_arr.pop_front();
            lines_arr.push_back({   iagw::VertexArray(),
                                    static_cast<float>(rand()%11 - 5) / 10,
                                    static_cast<float>(rand()%11 - 5) / 10,
                                    static_cast<float>(rand()%11 - 5) / 10});

            lines_arr.back().m_v.move(rand()%(sc_size.x - 30), rand()%(sc_size.y - 40));
            lines_arr.back().m_v.setColor(rand()%8, 2);
        }
        printw("%d", counter);

        for(auto i = 0; i <  lines_arr.size(); i++)
        {
            lines_arr[i].m_v.drawYourself();
            lines_arr[i].m_v.rotate(lines_arr[i].m_r);
            lines_arr[i].m_v.move(  lines_arr[i].m_vx,
                                    lines_arr[i].m_vy);
        }

        sc.show();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        sc.clear();

        counter++;
        counter = counter%240;
    }

    return 0;
}
