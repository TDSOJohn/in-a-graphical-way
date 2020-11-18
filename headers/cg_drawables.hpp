#ifndef cg_drawables_hpp
#define cg_drawables_hpp

#include "core_graphics.hpp"
#include "cg_virtual.hpp"
#include "cg_matrix.hpp"


namespace cg
{

    class Rectangle: public Shape
    {
    public:
                    Rectangle();
                    Rectangle(float x1, float y1, float x2, float y2);

        bool        intersects(const Rectangle& rec);
        void        drawYourself() const;
    };

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

#endif //cg_drawables_hpp
