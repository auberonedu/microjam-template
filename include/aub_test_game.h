#ifndef AUB_TEST_GAME_H
#define AUB_TEST_GAME_H

#include "bn_regular_bg_ptr.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_mj_small_pumpkin.h"
#include "bn_sprite_items_abd_candy.h"

#include "mj/mj_game.h"

#include "bn_sprite_items_aub_dot.h"

namespace aub
{

class aub_test_game : public mj::game
{

public:

    static constexpr int minimum_frames = 3 * 60; //!< Minimum number of frames per game.
    static constexpr int maximum_frames = 5 * 60; //!< Maximum number of frames per game.

    aub_test_game(int completed_games, const mj::game_data& data);

    [[nodiscard]] bn::string<16> title() const final
    {
        return "Test game!";
    }

    [[nodiscard]] int total_frames() const final
    {
        return _total_frames;
    }

    void fade_in(const mj::game_data& data) final;

    [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

    [[nodiscard]] bool victory() const final
    {
        return _victory;
    }

    void fade_out(const mj::game_data& data) final;

private:
    bn::sprite_ptr _playerSprite = bn::sprite_items::aub_dot.create_sprite(0,0);

    int _total_frames;
    int _show_result_frames = 30;

    bn::fixed gameSpeed = 1;

    bool _victory = false;
    bool _defeat = false;
};

}

#endif
