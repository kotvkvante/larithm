#include <stdlib.h>
#include <stdio.h>


// common/map
#include "la_map.h"

// common/objects
#include "invr.h"

static char _invr_textures[] = {'↓', '→', '↓', '←'};

la_obj_invr_t* obj_invr_new()
{
    return malloc(sizeof(la_obj_invr_t));
}

la_obj_invr_t* obj_invr_init(int x, int y)
{
    la_obj_invr_t* invr = obj_invr_new();
    obj_base_init_xyt((la_obj_base_t*)invr, x, y, LA_OBJ_TYPE_invr);
    invr->is_pressed = 0;
    invr->texture = '!';
    invr->lnkd_count = 0;
    return invr;
}

void obj_invr_set_direction(la_obj_invr_t* invr, int dir)
{
    invr->direction = dir;
}
