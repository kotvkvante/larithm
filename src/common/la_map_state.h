#ifndef LA_MAP_STATE_H
#define LA_MAP_STATE_H

#include "la_types.h"

typedef struct la_map_t la_map_t;
typedef struct la_obj_base_t la_obj_base_t;;
typedef struct la_obj_wall_t la_obj_wall_t;

typedef struct la_map_state_t
{
    int size_x, size_y;
    la_obj_base_t** objects;

    la_point_t character_pos;
    int current_character;


} la_map_state_t;

la_map_state_t* map_state_init_with(la_map_t* map, la_obj_base_t* obj);
la_map_state_t* map_state_init(la_map_t* map);


void map_state_add_wall(la_map_state_t* map_state, la_obj_wall_t* wall);

void map_state_print(la_map_state_t* map_state);


void map_state_close(la_map_state_t* map_state);

#endif /* end of include guard: LA_MAP_STATE_H */
