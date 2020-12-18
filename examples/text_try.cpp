#include <thread>
#include <chrono>
#include <deque>

#include <curses.h>

#include "../headers/Screen.hpp"
#include "../headers/Texture.hpp"


int main()
{
    iagw::Screen sc;
    iagw::vi2d sc_size = sc.returnSize();

    iagw::Texture t_1(10.f, 10.f, "examples/ASCII_art/book_open.txt");
    t_1.setColor(4, 0);
    t_1.setOrigin(20.f, 20.f);

    int counter = 0;
    while(true)
    {
        t_1.rotate(1.f);

        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(160));

        sc.clear();

        t_1.drawYourself();
        counter++;
        counter = counter%60;
    }

    return 0;
}
