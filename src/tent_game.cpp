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
    mj::game("tent")
{
    // for(int i = 0; i < SEGMENT_COUNT; i++) {
    //     _segments.push_back(bn::sprite_items::tent_seg.create_sprite(0, 0));
    // }
}

void tent_game::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

mj::game_result tent_game::play([[maybe_unused]] const mj::game_data& data)
{
    mj::game_result result;
    _victory = false;
    bn::fixed player_speed = 1;
    // bn::fixed angle = _playerSprite.rotation_angle();
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
    //_base_pos = {x, y}; // TODO: is set_x, set_y or explicit constructor faster?

    // bn::fixed angle_offset;
    // // Rotate around left end of sprite
    // for (int i = 0; i < SEGMENT_COUNT; i++) {
    //     angle_offset += angle;
    //     _segments[i].set_rotation_angle_safe(angle_offset);

    //     x += (SEGMENT_HALF_WIDTH * bn::degrees_cos(angle_offset));
    //     y -= (SEGMENT_HALF_WIDTH * bn::degrees_sin(angle_offset));
    //     _segments[i].set_position(x, y);
    //     x += (SEGMENT_HALF_WIDTH * bn::degrees_cos(angle_offset));
    //     y -= (SEGMENT_HALF_WIDTH * bn::degrees_sin(angle_offset));
    // }

    _tentacle.set_base_pos(bn::fixed_point(x, y));
    _tentacle.set_angle(angle);
    _tentacle.update();
    


    //_dot_sprite.set_position(x + (SEGMENT_HALF_WIDTH * bn::degrees_cos(angle)), y - (SEGMENT_HALF_WIDTH * bn::degrees_sin(angle)));
    // TODO: possible optimization by doing math directly with affine matrix

    return result;
}

void tent_game::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}
