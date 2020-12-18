#ifndef drawable_hpp
#define drawable_hpp


namespace iagw
{
    class RenderTarget;

    class Drawable
    {
        /// Added to use the syntax RenderTarget::draw(const Shape& s_in)
        //  (see last comment for more)
        friend class RenderTarget;
    public:
                                Drawable() { }

    protected:
        virtual void            drawYourself() = 0;
    };
}


#endif //  drawable_hpp


/**
*RenderTarget.draw(Something) seems nicer than Something.draw(RenderTarget)
*Syntax:
*RenderTarget::draw(const Shape& s_in)
*{
*    s_in.draw(*this);
*}
*Shape.draw is protected => Shape must be friend of RenderTarget
*/

/* Use
    attron(COLOR_PAIR(i));
    print_something();
    atroff(COLOR_PAIR(i));
*/
