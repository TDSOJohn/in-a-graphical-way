#include "V2d.hpp"
#include "Drawable.hpp"

namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// RenderTarget class
/// Drawing functions
/// colors bool and size
//////////////////////////////////////////////////////////////////////////////////
    class RenderTarget
    {
    public:
                    RenderTarget();
                    RenderTarget(const RenderTarget& r_in);
                    RenderTarget(const vi2d& size_in);
                    RenderTarget(int32_t x, int32_t y);

        void        draw(Drawable& s_in);

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

    protected:
        uint32_t    size_x,
                    size_y;

        bool        m_has_colors;
    };
}
