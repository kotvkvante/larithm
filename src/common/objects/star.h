#ifndef LA_STAR_H
#define LA_STAR_H

#include "base.h"

typedef struct la_map_t la_map_t;

typedef struct la_obj_star_t
{
    la_obj_base_t;
    int is_collected;

} la_obj_star_t;


la_obj_star_t* obj_star_new();
la_obj_star_t* obj_star_init(int x, int y);

void obj_star_collect(la_obj_star_t* star, la_map_t* map);
#endif /* end of include guard: LA_STAR_H */
