#include "mj_chooser_scene.h"
#include "mj_scene_type.h"

#include "mj_core.h"
#include "mj_game_list.h"
#include "mj_game.h"

#include <bn_unique_ptr.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>

namespace mj {

chooser_scene::chooser_scene(core& core) :
    _core(core) {
        bn::backdrop::set_color(bn::color(31, 0, 0));
        auto& text_generator = _core.small_text_generator();
        game_data fake_game_data = {
            core.text_generator(),
            core.small_text_generator(),
            core.big_text_generator(),
            core.random(),
            300
        };
        int y = -60;
        bn::unique_ptr<mj::game> game;
        bn::span<game_list::function_type> game_list_entries = game_list::get();
        for(int i = 0; i < game_list_entries.size(); i++) {
            game_list::function_type game_list_entry = game_list_entries[i];
            game.reset(game_list_entry(0, fake_game_data));
            auto title = game->title();
            _game_names.push_back(title);
            text_generator.generate({0, y}, title, _game_name_sprites);
            y += 10;
        }
        game.reset();
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