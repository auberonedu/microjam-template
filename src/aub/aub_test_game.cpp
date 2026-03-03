#include "aub_test_game.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "mj/mj_game_list.h"


namespace
{
    constexpr bn::string_view code_credits[] = { "Auberon Lopez" };
    constexpr bn::string_view graphics_credits[] = { "Kenney Game Assets" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(aub::aub_test_game)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace aub
{

aub_test_game::aub_test_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("aub"),
    _player(player({20, 0}, 2))
{

}

bn::string<16> aub_test_game::title() const {
    return "Leave the screen";
}

int aub_test_game::total_frames() const {
    return 300;
}

void aub_test_game::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

mj::game_result aub_test_game::play([[maybe_unused]] const mj::game_data& data)
{
    _player.update();
    mj::game_result result(victory(), false);
    return result;
}

void aub_test_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

bool aub_test_game::victory() const {
    return _player.out_of_bounds();
}
}
