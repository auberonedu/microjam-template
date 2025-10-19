#include "tent_game.h"

#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "mj/mj_game_list.h"


namespace
{
    constexpr bn::string_view code_credits[] = { "Auberon Lopez" };
    constexpr bn::string_view graphics_credits[] = { "Auberon Lopez" };
    constexpr bn::string_view sfx_credits[] = {""};
}

MJ_GAME_LIST_ADD(aub::tent_game)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
// MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)



namespace aub
{

// abd::abd_player player;

tent_game::tent_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("tent")
{

}

void tent_game::fade_in([[maybe_unused]] const mj::game_data& data)
{
   _playerSprite.set_position(0, 0);
}

mj::game_result tent_game::play([[maybe_unused]] const mj::game_data& data)
{
    mj::game_result result;
    _victory = false;
    bn::fixed player_speed = 1;
    bn::fixed angle = _playerSprite.rotation_angle();
    bn::fixed x = _playerSprite.x();
    bn::fixed y = _playerSprite.y();
    if(bn::keypad::left_held()) {
        x -= player_speed;
    }
    if(bn::keypad::right_held()) {
        x += player_speed;
    }
    if(bn::keypad::up_held()) {
        y -= player_speed;
    }
    if(bn::keypad::down_held()) {
       y +=  player_speed;
    }
    if(bn::keypad::l_held()) {
        angle += 10;
    }
    if(bn::keypad::r_held()) {
        angle -= 10;
    }
    _playerSprite.set_rotation_angle_safe(angle);
    _playerSprite.set_position(x, y);

    _dot_sprite.set_position(x + (PLAYER_SPRITE_HALF_WIDTH * bn::degrees_cos(angle)), y - (PLAYER_SPRITE_HALF_WIDTH * bn::degrees_sin(angle)));
    // TODO: possible optimization by doing math directly with affine matrix

    return result;
}

void tent_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}
