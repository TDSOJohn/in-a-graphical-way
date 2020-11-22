#include <chrono>
#include <iostream>
#include <curses.h>

#include "../headers/Event.hpp"


namespace iagw
{
    EventHandler::EventHandler(): mainThread(&EventHandler::eventLoop, this)
    {
    }

    bool EventHandler::getEvent(Event& event_in)
    {
        if(events.size() == 0)
            return 0;

        event_in = events.front();
        events.pop();

        return 1;
    }

    EventHandler::~EventHandler()
    {
        mainThread.join();
    }

    void EventHandler::eventLoop()
    {
        char c = 0;
        while(c != 'q')
        {
            c = getch();
            switch(c)
            {
                case 'q':
                    endwin();
                    mainThread.join();
            }
        }
    }
}
