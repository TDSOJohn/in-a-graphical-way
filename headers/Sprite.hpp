#ifndef sprite_hpp
#define sprite_hpp

#include "Drawable.hpp"
#include "Transformable.hpp"
#include "Texture.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// Sprite class\n
/// drawable and transformable that stores a std::unique_ptr to a Texture
//////////////////////////////////////////////////////////////////////////////////
    class Sprite : public Transformable, public Drawable
    {
    public:
                        Sprite();
                        Sprite(const Texture& t_in);

        void            setTexture(const Texture& t_in);

        void            drawYourself();
    };
}


#endif //   sprite_hpp
