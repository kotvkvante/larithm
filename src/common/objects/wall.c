#include <stdlib.h>
#include <stdio.h>

// objects
#include "wall.h"

la_obj_wall_t* obj_wall_new()
{
    return malloc(sizeof(la_obj_wall_t));
}

la_obj_wall_t* obj_wall_init(int x, int y)
{
    la_obj_wall_t* wall = obj_wall_new();
    obj_base_init_xyt((la_obj_base_t*)wall, x, y, LA_OBJ_TYPE_WALL);
    wall->texture = '#';
    return wall;
}
