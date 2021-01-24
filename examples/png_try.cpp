#include <thread>
#include <chrono>

#include "../headers/Screen.hpp"
#include "../headers/Texture.hpp"


int main()
{
    iagw::Screen sc;
    iagw::vi2d sc_size = sc.returnSize();

    sc.show();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    iagw::Texture t_1("examples/images/pixels.png");

    while(true)
    {
        sc.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

//        sc.clear();

//        t_1.drawYourself();
    }

    return 0;
}
