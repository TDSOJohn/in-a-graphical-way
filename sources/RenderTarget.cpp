#include "../headers/RenderTarget.hpp"

namespace iagw
{
    RenderTarget::RenderTarget()
    {}

    RenderTarget::RenderTarget(const RenderTarget& r_in)
    {}

    RenderTarget::RenderTarget(const vi2d& size_in):
        size_x(size_in.x),
        size_y(size_in.y)
    {}

    RenderTarget::RenderTarget(int32_t x, int32_t y):
        size_x(x),
        size_y(y)
    {}

    void RenderTarget::draw(const Shape& s_in)
    {
        s_in.drawYourself();
    }
}
