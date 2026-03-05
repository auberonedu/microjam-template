#include "aaa_planetoid.h"

namespace aaa{

    aaa_planetoids::aaa_planetoids([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("aaa")
    {}

    bn::string<16> aaa_planetoids::title() const{
        return "Planetoid";
    }

    int aaa_planetoids::total_frames() const {
    return 300; //5 seconds
    }

    mj::game_result aaa_planetoids::play([[maybe_unused]]const mj::game_data &data){
        return mj::game_result();
    }

    bool aaa_planetoids::victory() const{
        return false;
    }

    void aaa_planetoids::fade_in([[maybe_unused]]const mj::game_data &data){
    }

    void aaa_planetoids::fade_out([[maybe_unused]]const mj::game_data &data){
    }
}