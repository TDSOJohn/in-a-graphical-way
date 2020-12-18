#ifndef textures_hpp
#define textures_hpp

#include <string>

#include "V2d.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// Texture class\n
/// container that stores a 2D matrix of Pixel\n
/// not transformable, not drawable
//////////////////////////////////////////////////////////////////////////////////
    class Texture
    {
    public:
                    Texture(const Texture& text_in);
                    /// texture file name
                    Texture(const std::string& file_name);
                    /// position (x, y) and file name
                    Texture(int32_t x, int32_t y, const std::string& file_name);

                    ~Texture();

        void        loadFromFile(const std::string& fine_name);
        void        drawYourself();

    private:
        vf2d        size;
        char        **text_table;
    };
}

#endif //textures_hpp
