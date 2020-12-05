#include "V2d.hpp"
#include "Shape.hpp"


namespace iagw
{
    class RenderTarget
    {
        //  Added to use the syntax RenderTarget::draw(const Shape& s_in)
        //  (see last comment for more)
        friend class Shape;

    public:
                    RenderTarget();
                    RenderTarget(const RenderTarget& r_in);
                    RenderTarget(const vi2d& size_in);
                    RenderTarget(int32_t x, int32_t y);

        void        draw(Shape& s_in);

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

    protected:
        uint32_t    size_x,
                    size_y;

        bool        m_has_colors;
    };
}

/*
RenderTarget.draw(Something) seems nicer than Something.draw(RenderTarget)
Syntax:
RenderTarget::draw(const Shape& s_in)
{
    s_in.draw(*this);
}
Shape.draw is protected => Shape must be friend of RenderTarget
*/

/* Use
    attron(COLOR_PAIR(i));
    print_something();
    atroff(COLOR_PAIR(i));
*/
