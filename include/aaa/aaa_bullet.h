#ifndef AAA_BULLET_H
#define AAA_BULLET_H

#include <bn_sprite_ptr.h>
namespace aaa
{
    class aaa_Bullet
    {
    public:
        aaa_Bullet(bn::fixed_point starting_position, int xSpeed, int ySpeed);

        void update();
        bn::fixed_point BulletPos();

    private:
        // The sprite to display the player
        bn::sprite_ptr _sprite;

        // x,y speeds
        int _xSpeed;
        int _ySpeed;
    };
}
#endif