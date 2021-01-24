#include "V2d.hpp"
#include "Drawable.hpp"
#include "Texture.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// RenderTarget class
/// Drawing functions
/// colors bool and size
//////////////////////////////////////////////////////////////////////////////////
    class RenderTarget
    {
        /// Added to let Texture have the color array of the RenderTarget it draws to
        /// Main issue: Texture initializes itself with the colors of a specific RenderTarget
        friend class Texture;
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

        /// Stores the color coordinates for the 8 or 16 colors supported by target terminal 
        short       *colors_array;
    };
}
