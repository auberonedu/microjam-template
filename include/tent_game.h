#ifndef TENT_GAME_H
#define TENT_GAME_H

#include "bn_sprite_ptr.h"

#include "mj/mj_game.h"

#include "bn_sprite_items_tent_seg.h"
#include "bn_sprite_items_aub_dot.h"

namespace aub
{

const int SEGMENT_HALF_WIDTH = 16;
const int SEGMENT_COUNT = 3;

class tent_game : public mj::game
{

public:

    static constexpr int minimum_frames = 3 * 60; //!< Minimum number of frames per game.
    static constexpr int maximum_frames = 5 * 60; //!< Maximum number of frames per game.

    tent_game(int completed_games, const mj::game_data& data);

    [[nodiscard]] bn::string<16> title() const final
    {
        return "Tent game!";
    }

    [[nodiscard]] int total_frames() const final
    {
        return minimum_frames;
    }

    void fade_in(const mj::game_data& data) final;

    [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

    [[nodiscard]] bool victory() const final
    {
        return false; //_victory;
    }

    void fade_out(const mj::game_data& data) final;

private:
    bn::vector<bn::sprite_ptr, SEGMENT_COUNT> _segments;
    // bn::sprite_ptr _dot_sprite = bn::sprite_items::aub_dot.create_sprite(0,0);
    bool _victory = false;
    bn::fixed_point _base_pos = {0, 0};
    bn::fixed angle = 0;
};

}

#endif
