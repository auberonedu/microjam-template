#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

namespace blo
{

    class shark
    {
    public:
        /**
         * shark constructor
         *
         * @param starting_position the location of the shark
         */
        shark(bn::fixed_point starting_position);

    private:
        // The sprite to display the shark
        bn::sprite_ptr _sprite;
    }
}