#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// common/map
#include "la_map.h"
#include "la_map_state.h"

// common/objects
#include "character.h"
#include "wall.h"
#include "star.h"


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
    la_obj_star_t* star = (la_obj_star_t*)map_get_obj_by_type(map, x, y, LA_OBJ_TYPE_STAR);
    if(star != NULL)
        obj_star_collect(star, map);

    obj_chrt_force_move(chrt, map, x, y);
    return true;
}

void obj_chrt_force_move(la_obj_character_t* chrt, la_map_t* map, int x, int y)
{
    la_obj_base_t* obj = MAP_OBJECT(map, chrt->x, chrt->y);
    la_obj_base_t* tmp;

    if(obj == (la_obj_base_t*)chrt)
    {
        MAP_OBJECT(map, chrt->x, chrt->y) = chrt->obj;
        chrt->obj = MAP_OBJECT(map, x, y);
        MAP_OBJECT(map, x, y) = (la_obj_base_t*)chrt;
    }
    else
    {
        while(obj->obj != (la_obj_base_t*)chrt)
        {
            obj = obj->obj;
        }
        obj->obj = (la_obj_base_t*)chrt->obj;
        chrt->obj = MAP_OBJECT(map, x, y);
        MAP_OBJECT(map, x, y) = (la_obj_base_t*)chrt;
    }
    chrt->x = x;
    chrt->y = y;
}


int chrt_is_valid_pos(la_obj_character_t* chrt, la_map_t* map, int x, int y)
{
    if(!map_is_on_map(map, x, y))
        return false;
    if( MAP_SUBMAP_ELEMENT(map, colliders, x, y) == 1)
        return false;
    return true;
}

int chrt_exec(la_obj_character_t* chrt, la_map_t* map)
{
    int x = chrt->x;
    int y = chrt->y;
    la_obj_base_t* obj = MAP_OBJECT(map, x, y);

    while(obj != NULL)
    {
        printf("%d", obj->type);
        obj = obj->obj;
    }
    printf("\n");
}

void chrt_close(la_obj_character_t* chrt)
{

}
