#include "sdg_game.h"

namespace sdg{
    sdg_game::sdg_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("sdg")
    {}

    bn::string<16> sdg_game::title() const {
    return "Complete pattern";
    }

    int sdg_game::total_frames() const {
        return 300; // 5 seconds
    }

    mj::game_result sdg_game::play(const mj::game_data& data)
    {
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