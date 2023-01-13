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
    obj_base_init_xyt((la_obj_base_t*)door, x, y, LA_OBJ_TYPE_LEVR);
    return door;
}
