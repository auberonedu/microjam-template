#include "blo/blo_shark.h"

#include "bn_sprite_items_shark.h"

namespace blo
{
    /**
     * shark constructor
     *
     * @param starting_position the location to start the shark at
     */
    shark::shark(bn::fixed_point starting_position) : _sprite(bn::sprite_items::shark.create_sprite(starting_position))
    {
    }

    void shark::update(){
        _frames++;
    }

    void shark::punch(){
        _punched = true;
    }

    /**
     * Function that returns true if the shark has been hit, false if it hasnt
     *
     */
    bool shark::punched() const
    {
        return _punched;
    }

    /**
     * Function that returns true if the shark has fully emerged, false if it has not
     *
     */
    bool shark::isEmerged() const
    {
        return _frames >= 120;
    }

}