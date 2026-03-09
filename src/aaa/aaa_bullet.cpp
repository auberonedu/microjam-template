#include <bn_fixed.h>
#include <bn_math.h>
#include <bn_log.h>

#include "aaa/aaa_bullet.h"
#include "bn_sprite_items_aaa_bullet.h"

namespace aaa{

    aaa_Bullet::aaa_Bullet(bn::fixed_point starting_position, bn::fixed speed, bn::fixed angle) : _sprite(bn::sprite_items::aaa_bullet.create_sprite(starting_position)),
                                                                                                  _speed(speed),
                                                                                                  _angle(angle)
    {}

    void aaa_Bullet::update(){
        vx = -bn::degrees_lut_sin(_angle) * _speed;
        vy = -bn::degrees_lut_cos(_angle) * _speed;
        BN_LOG(vx);
        _sprite.set_x(_sprite.x() + vx);
        _sprite.set_y(_sprite.y() + vy);
    }
}