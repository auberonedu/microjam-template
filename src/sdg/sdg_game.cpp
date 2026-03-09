// TODO:
/*
 - Add vector to store set amount of inputs (lets start easy with 3)
 - Input detection
 - Add logic for correct inputs + win condition if all correct
 - Reset code if incorrect input is detected
 PAST THIS POINT IS ADVANCED
 - win animation
 - loss animation
 - difficulty scaling
 - sfx
 - background animations while gameplay is occuring
 - music?
*/

// <classes>
#include <bn_keypad.h>
#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>

// "classes"
#include "sdg_game.h"
#include "mj/mj_game_list.h"
#include "bn_sprite_items_sdg_arrow_sheet.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "Iker & Kevin James \"bigtoe\" Miclea" };
    constexpr bn::string_view graphics_credits[] = { "Kevin James \"bigtoe\" Miclea" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(sdg::sdg_game) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace sdg{
    sdg_game::sdg_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("sdg")
    {
    }
    const int challenge[4] = {0, 1, 2, 3};

    int progress = 0;
    bool challenge_completed = false;

    bn::string<16> sdg_game::title() const {
    return "Enter the code!";
    }

    int sdg_game::total_frames() const {
        return 300; // 5 seconds
    }

    mj::game_result sdg_game::play(const mj::game_data& data)
    {
        int input;
        if(bn::keypad::up_pressed()) { input = 0; }
        else if(bn::keypad::right_pressed()) { input = 1; }
        else if(bn::keypad::down_pressed()) { input = 2; }
        else if(bn::keypad::left_pressed()) { input = 3; }
        else {input = -1;}

        if(input != -1) {
            if(input == challenge[progress])
            {
                progress += 1;
                if (progress == 5) { challenge_completed = true; }
            }
            // reset if incorrect
            else { progress = 0; }
        }

        return mj::game_result();
    }

    bool sdg_game::victory() const {
        return false;
    }

    void sdg_game::fade_in([[maybe_unused]] const mj::game_data& data)
    {
    }

    void sdg_game::fade_out([[maybe_unused]] const mj::game_data& data)
    {
    }

}