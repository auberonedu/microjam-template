#include "aaa/aaa_enemy.h"

#include "bn_sprite_items_aaa_enemy.h"

namespace aaa
{
    /**
     * enemy constructor
     *
     * @param starting_position the location to start the enemy at
     * @param speed the pixels/frame the enemy moves at in each dimension
     */
    aaa_enemy::aaa_enemy(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::aaa_enemy.create_sprite(starting_position)),
                                                                               _speed(speed)
    {
    }
}