#include "blo_SharkASnack.h"

namespace blo {
    /**
 * Constructor for an instance of an SharkASnack
 *
 * @param completed_games how many microgames the player has completed so far
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
blo_SharkASnack::blo_SharkASnack([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("blo")
    {
    }

/**
 * The instructions given to the player at the beginning of the microgame.
 *
 * Must be <= 16 characters long
 */
bn::string<16> blo_SharkASnack::title() const {
    return "A title";
};

/**
 * How long the timer for the game should be set to in frames.
 *
 * 60 frames is approx 1 second
 */
int blo_SharkASnack::total_frames() const {
    return 600;
};

/**
 * play is repeatedly called while the microgame is playing.
 *
 * @param data shared information, such as a rng and number of frames left in the microgame
 * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
 */
mj::game_result blo_SharkASnack::play(const mj::game_data &data) {
    mj::game_result result(victory(), false);
    return result;
};

/**
 * Returns whether the player has won the microgame.
 *
 */
bool blo_SharkASnack::victory() const {
    return false;
};

/**
 * Called repeatedly as the game fades into view.
 *
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void blo_SharkASnack::fade_in(const mj::game_data &data) {

};

/**
 * Called repeatedly as the game fades into view.
 *
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void blo_SharkASnack::fade_out(const mj::game_data &data) {
    
};
}