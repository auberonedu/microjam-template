#ifndef TENT_GAME_H
#define TENT_GAME_H

#include "bn_sprite_ptr.h"

#include "mj/mj_game.h"
#include "tent_tentacle.h"

namespace tent
{

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
    bool _victory = false;
    Tentacle _tentacle;
};

}

#endif
