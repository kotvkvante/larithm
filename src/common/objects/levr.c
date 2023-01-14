#include <stdlib.h>
#include <stdio.h>


// common/map
#include "la_map.h"

// common/objects
#include "door.h"
#include "levr.h"

static char _levr_textures[] = {'!', '.'};

la_obj_levr_t* obj_levr_new()
{
    return malloc(sizeof(la_obj_levr_t));
}

la_obj_levr_t* obj_levr_init(int x, int y)
{
    la_obj_levr_t* levr = obj_levr_new();
    obj_base_init_xyt((la_obj_base_t*)levr, x, y, LA_OBJ_TYPE_LEVR);
    levr->is_pressed = 0;
    levr->texture = '!';
    levr->lnkd_count = 0;
    return levr;
}

void obj_levr_add_linked(la_obj_levr_t* levr, int k)
{
    if(levr->lnkd_count != 0)
    {
        printf("[E] Failed: %s\n", __func__);
        exit(-1);
    }
    levr->linked = malloc(sizeof(int) * 1);
    levr->linked[0] = k;
    levr->lnkd_count = 1;
}

void obj_levr_add_linked_arr(la_obj_levr_t* levr, int count, int* arr_k)
{
    if(levr->lnkd_count != 0)
    {
        printf("[E] Failed: %s;\n", __func__);
        exit(-1);
    }
    if(count < 0)
    {
        printf("[E] Failed %s: count < 0;\n", __func__);
        exit(-1);
    }

    levr->linked = malloc(sizeof(int) * count);
    levr->lnkd_count = count;

    for (size_t i = 0; i < count; i++) {
        levr->linked[i] = arr_k[i];
    }
}


int obj_levr_press(la_obj_levr_t* levr, la_map_t* map)
{
    levr->is_pressed = !(levr->is_pressed);
    levr->texture = _levr_textures[levr->is_pressed];

    for(int i = 0; i < levr->lnkd_count; i++)
    {
        int k = levr->linked[i];
        obj_door_switch((la_obj_door_t*)map->objects[k], map);
    }

    return true;
}

// void obj_levr_affect_on(la_obj_levr_t* levr, la_obj_base_t* obj, la_map_t* map)
// {
//     if(obj->type == LA_OBJ_TYPE_DOOR)
//         obj_door_switch((la_obj_door_t*)obj, map);
//     if(obj->type == LA_OBJ_TYPE_WALL)
//         printf("[L] You can't affect on Wall!\n");
// }
