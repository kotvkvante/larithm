#ifndef LA_WALL_H
#define LA_WALL_H

#include "base.h"

typedef struct la_obj_wall_t
{
    la_obj_base_t;
} la_obj_wall_t;

la_obj_wall_t* obj_wall_new();
la_obj_wall_t* obj_wall_init(int x, int y);

#endif /* end of include guard: LA_WALL_H */
