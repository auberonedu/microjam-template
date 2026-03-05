#include "mj_chooser_scene.h"
#include "mj_scene_type.h"

#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

namespace mj {

chooser_scene::chooser_scene(core& core) :
    _core(core) {
        bn::backdrop::set_color(bn::color(31, 0, 0));
    }

[[nodiscard]] bn::optional<scene_type> chooser_scene::update() {
    bn::optional<scene_type> next_scene = {};

    if(bn::keypad::a_pressed()) {
        bn::backdrop::set_color(bn::color(31, 31, 0));
    }
    if(bn::keypad::start_pressed()) {
        next_scene.emplace(mj::scene_type::TITLE);
    }
    return next_scene;
}


}