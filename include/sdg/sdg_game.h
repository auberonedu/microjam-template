// Include guard 
#ifndef SDG_GAME_H 
#define SDG_GAME_H

#include "mj/mj_game.h"
namespace sdg{
    class sdg_game : public mj::game {
    public:
    // Constructor
    sdg_game(int completed_games, const mj::game_data& data);

    // Required overrides
    bn::string<16> title() const override;

    int total_frames() const override;

    mj::game_result play(const mj::game_data& data) override;

    bool victory() const override;

    
    void fade_in(const mj::game_data& data) override;

    
    void fade_out(const mj::game_data& data) override;
}; 
}

#endif