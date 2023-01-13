#ifndef LA_CHARACTER_H
#define LA_CHARACTER_H

#include "base.h"

typedef struct la_map_t la_map_t;
typedef struct la_map_state_t la_map_state_t;

typedef struct la_obj_character_t
{
    la_obj_base_t;
} la_obj_character_t;

la_obj_character_t* obj_chrt_init(int x, int y);

int chrt_move(la_obj_character_t* chrt, la_map_t* map, int dx, int dy);
int chrt_move_dxdy(la_obj_character_t* chrt, la_map_t* map, int dx, int dy);
void obj_chrt_force_move(la_obj_character_t* chrt, la_map_t* map, int x, int y);
int chrt_is_valid_pos(la_obj_character_t* chrt, la_map_t* map, int x, int y);


#endif /* end of include guard: LA_CHARACTER_H */
