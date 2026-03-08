
#include "aaa/aaa_bullet.h"
#include "bn_sprite_items_aaa_bullet.h"

namespace aaa{

    aaa_Bullet::aaa_Bullet(bn::fixed_point starting_position, int xSpeed, int ySpeed) : _sprite(bn::sprite_items::aaa_bullet.create_sprite(starting_position)),
                                                                                        _xSpeed(xSpeed),
                                                                                        _ySpeed(ySpeed)
    {}

    void aaa_Bullet::update(){
        if(_xSpeed != 0){
            _sprite.set_x(_sprite.x() + _xSpeed);
        }
        if(_ySpeed != 0){
            _sprite.set_y(_sprite.y() + _ySpeed);
        }
    }
}