#include "blo/shark.h"

#include <bn_keypad.h>

namespace blo
{
    /**
     * player constructor
     *
     * @param starting_position the location to start the player at
     */
    shark::shark(bn::fixed_point starting_position) : _sprite(bn::sprite_items::shark.create_sprite(starting_position))
    {
    }

    /**
     * Function that returns true if the shark has not been hit yet, false if it has
     *
     */
    bool shark::isAlive()
    {
        return false;
    }

    /**
     * Function that returns true if the shark has fully emerged, false if it has not
     *
     */
    bool shark::isEmerged()
    {
        return false;
    }

}