#ifndef transformable_hpp
#define transformable_hpp

#include <cmath>
#include <algorithm>

#include "V2d.hpp"
#include "Transform.hpp"
#include "Rect.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// light-weight Node Structure\n
/// contains a vf2d to stor (x, y) position
//////////////////////////////////////////////////////////////////////////////////
    struct Node
    {
        vf2d    pos;
    };


//////////////////////////////////////////////////////////////////////////////////
///  Generic virtual Transformable class
//////////////////////////////////////////////////////////////////////////////////
    class Transformable
    {
    public:
                        /// default constructor sets origin and position to (0,0),\n
                        /// rotation to 0
                        Transformable();
                        /// copy constructor copies origin, position and rotation of transf_in
                        Transformable(const Transformable& transf_in);
                        /// (x_in, y_in) starting position of the transformable
                        /// rot_in starting rotation of the transformable
                        Transformable(int32_t x_in, int32_t y_in, float rot_in = 0.f);

        /// return position of the transformable as vf2d
        vf2d            getPosition() { return m_position; }
        /// !!!MISSING add setPosition implementation
        void            setPosition(float x, float y);
        /// !!!MISSING add setPosition implementation
        void            setPosition(const vf2d& new_pos);

        /// return local bounds (bounding rectangle with first vertex as (0, 0))
        Rectf           getLocalBounds() const { return local_bounds; }
        /// return global bounds
        Rectf           getGlobalBounds() const { return(m_transform.transformRect(local_bounds)); }

        /// return const Trasform& of the trasformable
        const Transform& getTransform();

        /// move transformable and origin by (x, y)
        void            move(float x, float y);
        /// move transformable and origin by (move_vec)
        void            move(const vf2d& move_vec);

        /// rotate by r degrees
        void            rotate(float r);
        /// set rotation to r degrees (NOT IMPLEMENTED YET)
        void            setRotation(float r);
        /// return float rotation in degrees (0, 360)
        float           getRotation() const;

        /// set origin of rotation and scaling (x, y coordinates)
        void            setOrigin(float x, float y);
        /// set origin of rotation and scaling (origin vector)
        void            setOrigin(const vf2d& new_origin);
        /// return vf2d origin of the transformable
        vf2d            getOrigin() const;

    protected:
        float           m_rotation;
        vf2d            m_origin;
        vf2d            m_position;
        Rectf           local_bounds;
        Transform       m_transform;

        bool            transf_need_update;

    protected:
        /// Generates localBound Rect. Not called in virtual Transformable class,\n
        /// needs to be called by derived class at construction, after arr_nodes is populated
        virtual void    setLocalBounds() = 0;

        /// Update transformation matrix
        void            updateTransform();
    };

}

#endif //transformable_hpp
