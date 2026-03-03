#ifndef AUB_TEST_GAME_H
#define AUB_TEST_GAME_H

#include <bn_sprite_ptr.h>

#include "mj/mj_game.h"
#include "aub/player.h"

namespace aub
{

class aub_test_game : public mj::game
{
    public:
        aub_test_game(int completed_games, const mj::game_data& data);

        bn::string<16> title() const override;

        int total_frames() const override;

        void fade_in(const mj::game_data& data) override;

        mj::game_result play(const mj::game_data& data) override;

        bool victory() const override;

        void fade_out(const mj::game_data& data) override;

    private:
        player _player;
};

}

#endif
