#ifndef TENT_TENTACLE_H
#define TENT_TENTACLE_H

#include "bn_sprite_ptr.h"
#include "bn_vector.h"

namespace tent {

const int SEGMENT_HALF_WIDTH = 16;
const int MAX_SEGMENTS = 32;
class Tentacle
{
private:
    bn::vector<bn::sprite_ptr, MAX_SEGMENTS> _segment_sprs;
    int _segment_count;
    bn::fixed_point _base_pos;
    bn::fixed _angle;
    
public:
    Tentacle(int segment_count);
    ~Tentacle();
    void set_angle(bn::fixed angle);
    bn::fixed get_angle();
    void set_base_pos(bn::fixed_point base_pos);
    bn::fixed_point get_base_pos(); // Returns a duplicate - is that good?
    void update();
};

}
#endif 