#ifndef LA_CHARACTER_H
#define LA_CHARACTER_H

#include "base.h"

#define LA_OBJ_TYPE_CHRT '*'
typedef struct la_obj_character_t
{
    la_obj_base_t;
} la_obj_character_t;

int chrt_move_up(la_obj_character_t* chrt);
int chrt_is_valid_pos(
    la_obj_character_t* chrt, la_map_t* map, la_map_state_t* map_state,
    int x, int y);

#endif /* end of include guard: LA_CHARACTER_H */
