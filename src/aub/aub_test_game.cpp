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

    constexpr int MAX_X = bn::display::width() / 2;
    constexpr int MIN_X = - bn::display::width() / 2;
    constexpr int MAX_Y = bn::display::height() / 2;
    constexpr int MIN_Y = - bn::display::height() / 2;

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
    _playerSprite(bn::sprite_items::aub_dot.create_sprite(0, 0))
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
   _playerSprite.set_position(0, 0);
}

mj::game_result aub_test_game::play([[maybe_unused]] const mj::game_data& data)
{
    if(bn::keypad::left_held()) {
        _playerSprite.set_x(_playerSprite.x() - PLAYER_SPEED);
    }
    if(bn::keypad::right_held()) {
        _playerSprite.set_x(_playerSprite.x() + PLAYER_SPEED);
    }
    if(bn::keypad::up_held()) {
        _playerSprite.set_y(_playerSprite.y() - PLAYER_SPEED);
    }
    if(bn::keypad::down_held()) {
        _playerSprite.set_y(_playerSprite.y() + PLAYER_SPEED);
    }

    mj::game_result result(victory(), false);
    return result;
}

void aub_test_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

bool aub_test_game::victory() const {
    return out_of_bounds();
}

bool aub_test_game::out_of_bounds() const {
    return _playerSprite.x() > MAX_X ||
           _playerSprite.x() < MIN_X ||
           _playerSprite.y() > MAX_Y ||
           _playerSprite.y() < MIN_Y;
}

}
