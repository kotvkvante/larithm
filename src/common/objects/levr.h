#ifndef LA_LEVR_H
#define LA_LEVR_H


#include "base.h"

typedef struct la_obj_levr_t
{
    la_obj_base_t;
    int is_pressed;

    int lnkd_count;
    int* linked;
} la_obj_levr_t;


la_obj_levr_t* obj_levr_init(int x, int y);
la_obj_levr_t* obj_levr_new();

void obj_levr_add_linked(la_obj_levr_t* levr, int k);
void obj_levr_add_linked_arr(la_obj_levr_t* levr, int count, int* arr_k);

int obj_levr_press(la_obj_levr_t* levr, la_map_t* map);

#endif /* end of include guard: LA_LEVR_H */
