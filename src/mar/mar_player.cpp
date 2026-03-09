#include "mar/mar_player.h"

#include <bn_keypad.h>
#include <bn_rect.h>

#include "bn_sprite_items_square.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace mar
{

    /**
     * mar_player constructor
     *
     * @param starting_position the location to start the mar_player at
     * @param speed the pixels/frame the mar_player moves at in each dimension
     */
    mar_player::mar_player(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::square.create_sprite(starting_position)), _speed(speed)
    {}

    /**
     * Reads from the d-pad and moves the mar_player by one frame accordingly.
     */
    void mar_player::update()
    {
        // if (bn::keypad::left_held())
        // {
        //     _sprite.set_x(_sprite.x() - _speed);
        // }
        // if (bn::keypad::right_held())
        // {
        //     _sprite.set_x(_sprite.x() + _speed);
        // }
        if (bn::keypad::up_held() && _sprite.y() > MIN_Y)
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held() && _sprite.y() < MAX_Y)
        {
            _sprite.set_y(_sprite.y() + _speed);
        }
    }

    /**
     * Returns whether the player has left the screen
     *
     * @return true if the player has left the screen, false if it is still on the screen
     */
    bool mar_player::out_of_bounds() const
    {
        return _sprite.x() > MAX_X ||
               _sprite.x() < MIN_X ||
               _sprite.y() > MAX_Y ||
               _sprite.y() < MIN_Y;
    }
}