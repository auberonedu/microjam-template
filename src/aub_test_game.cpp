#include "aub_test_game.h"

#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "mj/mj_game_list.h"


namespace
{
    constexpr bn::string_view code_credits[] = { "Auberon Lopez" };
    constexpr bn::string_view graphics_credits[] = { "Kenney Game Assets" };
    constexpr bn::string_view sfx_credits[] = {""};
}

MJ_GAME_LIST_ADD(aub::aub_test_game)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
// MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace aub
{

// abd::abd_player player;

aub_test_game::aub_test_game(int completed_games, const mj::game_data& data) :
    mj::game("aub")
{
    constexpr int frames_diff = maximum_frames - minimum_frames;
    constexpr int maximum_speed_completed_games = 30;

    completed_games = bn::min(completed_games, maximum_speed_completed_games);

    int frames_reduction = (frames_diff * completed_games) / maximum_speed_completed_games;
    _total_frames = maximum_frames - frames_reduction;
    _total_frames -= data.random.get_int(60);
    _total_frames = bn::clamp(_total_frames, minimum_frames, maximum_frames);

    gameSpeed = 1 + completed_games*1.0/maximum_speed_completed_games;
    if(gameSpeed > 2){
        gameSpeed = 2;
    }

}

void aub_test_game::fade_in([[maybe_unused]] const mj::game_data& data)
{
   _playerSprite.set_position(0, 0);
}

mj::game_result aub_test_game::play(const mj::game_data& data)
{
    mj::game_result result;
    _victory = true;
    bn::fixed player_speed = 2;
    if(bn::keypad::left_held()) {
        _playerSprite.set_x(_playerSprite.x() - player_speed);
    }
    if(bn::keypad::right_held()) {
        _playerSprite.set_x(_playerSprite.x() + player_speed);
    }
    if(bn::keypad::up_held()) {
        _playerSprite.set_y(_playerSprite.y() - player_speed);
    }
    if(bn::keypad::down_held()) {
        _playerSprite.set_y(_playerSprite.y() + player_speed);
    }

    return result;
}

void aub_test_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}
