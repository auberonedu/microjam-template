#include "tent_tentacle.h"

#include "bn_math.h"

#include "bn_sprite_items_tent_seg.h"

namespace tent {
Tentacle::Tentacle(int segment_count) :
 _segment_count(segment_count),
 _base_pos(bn::fixed_point(0, 0)),
 _angle(0)
{
    BN_ASSERT(segment_count > 0 && segment_count < MAX_SEGMENTS);

    for(int i = 0; i < _segment_count; i++) {
         _segment_sprs.push_back(bn::sprite_items::tent_seg.create_sprite(0, 0));
    }
}

void Tentacle::set_base_pos(bn::fixed_point base_pos) { _base_pos = base_pos; }
bn::fixed_point Tentacle::get_base_pos() { return _base_pos; }

void Tentacle::set_angle(bn::fixed angle) { _angle = angle; }
bn::fixed Tentacle::get_angle() { return _angle; }

void Tentacle::update() {
    bn::fixed angle_offset = 0;
    bn::fixed x = _base_pos.x();
    bn::fixed y = _base_pos.y();

    for (int i = 0; i < _segment_count; i++) {
        angle_offset += _angle;
        _segment_sprs[i].set_rotation_angle_safe(angle_offset);

        x += (SEGMENT_HALF_WIDTH * bn::degrees_cos(angle_offset));
        y -= (SEGMENT_HALF_WIDTH * bn::degrees_sin(angle_offset));
        _segment_sprs[i].set_position(x, y);
        x += (SEGMENT_HALF_WIDTH * bn::degrees_cos(angle_offset));
        y -= (SEGMENT_HALF_WIDTH * bn::degrees_sin(angle_offset));
    }
}



Tentacle::~Tentacle()
{
}

}
