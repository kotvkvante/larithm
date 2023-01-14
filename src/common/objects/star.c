#include <stdlib.h>
#include <stdio.h>

// common/map
#include "la_map.h"

// common/objects
#include "star.h"

static char _star_textures[] = {};

la_obj_star_t* obj_star_new()
{
    return malloc(sizeof(la_obj_star_t));
}

la_obj_star_t* obj_star_init(int x, int y)
{
    la_obj_star_t* star = obj_star_new();
    obj_base_init_xyt((la_obj_base_t*)star, x, y, LA_OBJ_TYPE_STAR);
    star->texture = '+';
    star->is_collected = false;

    return star;
}

void obj_star_collect(la_obj_star_t* star, la_map_t* map)
{
    if(star->is_collected) return;
    star->is_collected = true;
    star->texture = 'v';

    map_inc_score(map);
}
