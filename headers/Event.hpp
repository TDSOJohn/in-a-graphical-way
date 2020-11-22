#ifndef event_hpp
#define event_hpp

#include <thread>
#include <queue>


namespace iagw
{
    enum Key
	{
		NONE,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		UP, DOWN, LEFT, RIGHT,
		SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL, PERIOD,
		EQUALS, COMMA, MINUS,
		OEM_1, OEM_2, OEM_3, OEM_4, OEM_5, OEM_6, OEM_7, OEM_8,
		CAPS_LOCK, ENUM_END
	};

    struct Event
    {
        Key                 keyPressed;

                            Event(): keyPressed(Key::NONE) {}
                            Event(Key key_in);

        Event& operator=    (const Event& v) = default;
        bool operator ==    (const Event& rhs) const { return (this->keyPressed == rhs.keyPressed); }
        bool operator !=    (const Event& rhs) const { return (this->keyPressed != rhs.keyPressed); }
    };


    class EventHandler
    {
    public:
                            EventHandler();
                            ~EventHandler();

        bool                getEvent(Event& event_in);

    private:
        void                eventLoop();

    private:
        std::thread         mainThread;
        std::queue<Event>   events;
    };
}

#endif //event_hpp
