#include <stdlib.h>
#include <stdio.h>

// objects
#include "wall.h"

la_obj_wall_t* obj_wall_new()
{
    return malloc(sizeof(la_obj_wall_t));
}

void obj_wall_init(la_obj_wall_t* wall, int x, int y, int durability)
{
    obj_base_init_xy((la_obj_base_t*)wall, x, y);
    ((la_obj_base_t*)wall)->type = LA_OBJ_TYPE_WALL;
    wall->durability = durability;
}
