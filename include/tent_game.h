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
    tent_game(int completed_games, const mj::game_data& data);

    [[nodiscard]] bn::string<16> title() const final
    {
        return "Tent game!";
    }

    [[nodiscard]] int total_frames() const final
    {
        return maximum_frames;
    }

    void fade_in(const mj::game_data& data) final;

    [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

    [[nodiscard]] bool victory() const final
    {
        return _victory;
    }

    void fade_out(const mj::game_data& data) final;

private:
    bn::vector<bn::sprite_ptr, SEGMENT_COUNT> _segments;
    bool _victory = false;
    bn::fixed_point _base_pos = {0, 0};
    bn::fixed angle = 0;
};

}

#endif
