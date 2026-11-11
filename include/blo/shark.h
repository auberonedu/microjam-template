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

        // Checks if the shark is successfully hit on time
        bool isAlive() const;

        // Checks to see if the shark is fully emerged (Ready to hit)
        bool isEmerged() const;

    private:
        // The sprite to display the shark
        bn::sprite_ptr _sprite;
    }
}