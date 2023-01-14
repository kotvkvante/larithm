#include <stdlib.h>
#include <stdio.h>


// common/map
#include "la_map.h"
#include "la_map_collider.h"

// common/objects
#include "door.h"

static char _door_textures[] = {'D', 'd'};

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

// void obj_door_set(la_obj_door_t* door, int x, int y)
// {
//     door->door.x = x;
//     door->door.y = y;
// }



void obj_door_switch(la_obj_door_t* door, la_map_t* map)
{
    door->is_opened = !door->is_opened;
    door->texture   = _door_textures[door->is_opened];
    map_cldr_switch(map, door->x, door->y);
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
    {
        obj_door_open_door(door);
        map_cldr_remove(map, door->x, door->y);
    }
    else
    {
        obj_door_close_door(door);
        map_cldr_set(map, door->x, door->y);
    }
}
