#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "la_map.h"
#include "la_map_state.h"
#include "character.h"
#include "wall.h"


typedef int (*la_action_f)(la_map_t*, la_map_state_t*);

la_obj_character_t* obj_chrt_new()
{
    return malloc(sizeof(la_obj_character_t));
}

la_obj_character_t* obj_chrt_init(int x, int y)
{
    la_obj_character_t* chrt = obj_chrt_new();
    obj_base_init_xyt((la_obj_base_t*)chrt, x, y, LA_OBJ_TYPE_CHRT);
    chrt->texture = '*';
    return chrt;
}

int chrt_move_dxdy(la_obj_character_t* chrt, la_map_t* map, int dx, int dy)
{
    return chrt_move(chrt, map, chrt->x + dx, chrt->y + dy);
}

int chrt_move(la_obj_character_t* chrt, la_map_t* map, int x, int y)
{
    if(!chrt_is_valid_pos(chrt, map, x, y))
    {
        return false;
    }
    obj_chrt_force_move(chrt, map, x, y);
    return true;
}

void obj_chrt_force_move(la_obj_character_t* chrt, la_map_t* map, int x, int y)
{
    MAP_OBJECT(map, chrt->x, chrt->y) = NULL;
    MAP_OBJECT(map, x, y) = (la_obj_base_t*)chrt;
    chrt->x = x;
    chrt->y = y;
}


int chrt_is_valid_pos(la_obj_character_t* chrt, la_map_t* map, int x, int y)
{
    if(!map_is_on_map(map, x, y))
        return false;
    if(MAP_SUBMAP_ELEMENT(map, colliders, x, y) == 1)
        return false;
    return true;
}
