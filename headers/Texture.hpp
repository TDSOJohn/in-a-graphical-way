#ifndef textures_hpp
#define textures_hpp

#include <string>

#include "Shape.hpp"


namespace cg
{
    class Texture: public Shape
    {
    public:
                    Texture();
                    Texture(int32_t x, int32_t y, const std::string& file_name);
                    Texture(const std::string& file_name);

                    ~Texture();

        void        loadFromFile(const std::string& fine_name);
        void        drawYourself() const;

    private:
        char        **text_table;
    };
}

#endif //textures_hpp
