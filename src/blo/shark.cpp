#include "blo/shark.h"

#include <bn_keypad.h>
#include "bn_sprite_items_shark.h"

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
    bool shark::punched() const
    {
        return false;
    }

}