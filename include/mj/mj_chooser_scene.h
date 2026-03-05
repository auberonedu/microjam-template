#ifndef MJ_CHOOSER_SCENE_H
#define MJ_CHOOSER_SCENE_H

#include <bn_string.h>
#include <bn_vector.h>
#include <bn_sprite_ptr.h>

#include "mj_scene.h"

namespace mj
{

class core;

class chooser_scene final : public scene
{

public:
    explicit chooser_scene(core& core);

    [[nodiscard]] bn::optional<scene_type> update() final;

private:
    core& _core;
    int _cursor_idx;
    bn::vector<bn::sprite_ptr, 16*64> _game_name_sprites;

    bn::vector<bn::string<16>, 64> _game_names;
};

}

#endif