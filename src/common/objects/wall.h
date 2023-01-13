#ifndef LA_WALL_H
#define LA_WALL_H

#include "base.h"

#define LA_OBJ_TYPE_WALL '#'
typedef struct la_obj_wall_t
{
    la_obj_base_t;
    int durability;
} la_obj_wall_t;

la_obj_wall_t* obj_wall_new();
void obj_wall_init(la_obj_wall_t* wall, int x, int y, int durability);

#endif /* end of include guard: LA_WALL_H */
