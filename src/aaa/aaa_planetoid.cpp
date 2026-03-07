#include "aaa_planetoid.h"
#include "mj/mj_game_list.h"

MJ_GAME_LIST_ADD(aaa::aaa_planetoids);
namespace
{
    constexpr bn::string_view code_credits[] = {"KJ, AK"};
    constexpr bn::string_view graphics_credits[] = {"Planetoids Graphics Assets"};
    constexpr bn::string_view sfx_credits[] = {"none"};
    constexpr bn::string_view music_credits[] = {"none"};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(aaa::aaa_planetoids) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace aaa
{

    aaa_planetoids::aaa_planetoids([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("aaa")
    {
        bn::random random;

        for (int i = 0; i < enemies.max_size(); i++)
        {
            bn::fixed_point pos(random.get_int(-200, 200), random.get_int(-120, 120)); // added extra so some enemies spawn off-screen
            bn::fixed speed = random.get_fixed(.2, .4);                                // nice slow moving enemies

            enemies.push_back(aaa_enemy({pos}, speed));
        }
    }

    bn::string<16> aaa_planetoids::title() const
    {
        return "Planetoids";
    }

    int aaa_planetoids::total_frames() const
    {
        return 480;
    }

    mj::game_result aaa_planetoids::play([[maybe_unused]] const mj::game_data &data)
    {

        for (aaa_enemy &enemy : enemies)
        {
            enemy.update();
        }
        return mj::game_result();
    }

    bool aaa_planetoids::victory() const
    {
        return false;
    }

    void aaa_planetoids::fade_in([[maybe_unused]] const mj::game_data &data)
    {
    }

    void aaa_planetoids::fade_out([[maybe_unused]] const mj::game_data &data)
    {
    }
}