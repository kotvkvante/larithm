#ifndef LA_DOOR_H
#define LA_DOOR_H

#include "base.h"
#include "point.h"

typedef struct la_map_t la_map_t;

typedef struct la_obj_door_t
{
    la_obj_base_t;
    int is_opened;
    la_point_t door;
} la_obj_door_t;

la_obj_door_t* obj_door_new();
la_obj_door_t* obj_door_init(int x, int y);

void obj_door_switch(la_obj_door_t* door, la_map_t* map);
void obj_door_open_door(la_obj_door_t* door);
void obj_door_close_door(la_obj_door_t* door);
void obj_door_map_sync(la_obj_door_t* door, la_map_t* map);

#endif /* end of include guard: LA_DOOR_H */
