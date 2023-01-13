#include <stdlib.h>
#include <stdio.h>


// common/map
#include "la_map.h"

// common/objects
#include "door.h"

la_obj_door_t* obj_door_new()
{
    return malloc(sizeof(la_obj_door_t));
}

la_obj_door_t* obj_door_init(int x, int y)
{
    la_obj_door_t* door = obj_door_new();
    obj_base_init_xyt((la_obj_base_t*)door, x, y, LA_OBJ_TYPE_DOOR);
    door->is_opened = false;
    door->texture = 'D';
    return door;
}

void obj_door_set(la_obj_door_t* door, int x, int y)
{
    door->door.x = x;
    door->door.y = y;
}

void obj_door_close_door(la_obj_door_t* door)
{
    door->is_opened = false;
    door->texture = 'D';
}

void obj_door_open_door(la_obj_door_t* door)
{
    door->is_opened = true;
    door->texture = 'd';
}

void obj_door_map_sync(la_obj_door_t* door, la_map_t* map)
{
    if(door->is_opened)
        MAP_SUBMAP_ELEMENT(map, colliders, door->door.x, door->door.y) = 0;
    else
        MAP_SUBMAP_ELEMENT(map, colliders, door->door.x, door->door.y) = 1;
}
