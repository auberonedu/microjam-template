#include "aub/player.h"

#include <bn_keypad.h>

#include "bn_sprite_items_aub_dot.h"

namespace aub {

player::player(bn::fixed_point starting_position, bn::fixed speed) :
    _sprite(bn::sprite_items::aub_dot.create_sprite(starting_position)),
    _speed(speed)
    {}
    
void player::update() {
    if(bn::keypad::left_held()) {
        _sprite.set_x(_sprite.x() - _speed);
    }
    if(bn::keypad::right_held()) {
        _sprite.set_x(_sprite.x() + _speed);
    }
    if(bn::keypad::up_held()) {
        _sprite.set_y(_sprite.y() - _speed);
    }
    if(bn::keypad::down_held()) {
        _sprite.set_y(_sprite.y() + _speed);
    }
}

bool player::out_of_bounds() const {
    return _sprite.x() > MAX_X ||
           _sprite.x() < MIN_X ||
           _sprite.y() > MAX_Y ||
           _sprite.y() < MIN_Y;
}
}