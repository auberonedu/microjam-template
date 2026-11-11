#include "blo/player.h"

#include <bn_keypad.h>

namespace blo {
    /**
     * player constructor
     */
    player::player()
    {
    }

    void player::update() {
        if (bn::keypad::a_pressed()){
            
        }
    }

    bool player::hasSnack() const {
        return _has_snack;

    }

}