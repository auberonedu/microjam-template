#include "mar_mars_escape.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = { "Auberon Lopez" };
    constexpr bn::string_view graphics_credits[] = { "Kenney Game Assets" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

namespace mar{

mar_mars_escape::mar_mars_escape([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("mar")
    {}

}