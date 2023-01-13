#include <stdlib.h>
#include <stdio.h>

// objects
#include "base.h"
// Owner must free object
la_obj_base_t* obj_base_new()
{
    return malloc(sizeof(la_obj_base_t));
}

void obj_base_init_xy(la_obj_base_t* base, int x, int y)
{
    base->type = LA_OBJ_TYPE_BASE;
    base->x = x;
    base->y = y;
}

// void la_base_set_texture()
// {
//
// }

// void la_base_force_move_to(la_obj_base_t* base, int x, int y)
// {
//     base->x = x;
//     base->y = y;
// }
//
// void la_base_inc_x(la_obj_base_t* base) { base->x++; }
// void la_base_dec_x(la_obj_base_t* base) { base->x--; }
// void la_base_inc_y(la_obj_base_t* base) { base->y++; }
// void la_base_dec_y(la_obj_base_t* base) { base->y--; }

// void la_base_close(la_obj_base_t* )
