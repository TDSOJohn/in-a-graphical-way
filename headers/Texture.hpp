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
                    /// texture file name
                    Texture(const std::string& file_name);

                    ~Texture();

        /// Loads PNG from file path given as string, stores it in an unsigned char **
        void        loadFromFile(const std::string& file_name);

    private:
        vf2d        size;
        unsigned char
                    **data_table;
    };
}

#endif //textures_hpp
