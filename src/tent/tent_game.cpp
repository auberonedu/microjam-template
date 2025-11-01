#include "tent_game.h"

#include "bn_log.h"
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

MJ_GAME_LIST_ADD(tent::tent_game)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
// MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)



namespace tent
{

tent_game::tent_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("tent"),
    _tentacle(Tentacle(SEGMENT_COUNT))
{

}

void tent_game::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

mj::game_result tent_game::play([[maybe_unused]] const mj::game_data& data)
{
    mj::game_result result;
    _victory = false;
    bn::fixed player_speed = 1;
    bn::fixed x = _tentacle.get_base_pos().x();
    bn::fixed y = _tentacle.get_base_pos().y();
    bn::fixed angle = _tentacle.get_angle();
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

    _tentacle.set_base_pos(bn::fixed_point(x, y));
    _tentacle.set_angle(angle);
    _tentacle.update();

    return result;
}

void tent_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}
