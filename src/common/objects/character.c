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

void obj_chrt_init(la_obj_character_t* chrt, int x, int y)
{
    obj_base_init_xy((la_obj_base_t*)chrt, x, y);
    ((la_obj_base_t*)chrt)->type = LA_OBJ_TYPE_CHRT;
}


int chrt_move_up(la_obj_character_t* chrt)
{

}

int chrt_is_valid_pos(
    la_obj_character_t* chrt, la_map_t* map, la_map_state_t* map_state,
    int x, int y)
{
    if(map_state->objects[x + y * map_state->size_x]->type == LA_OBJ_TYPE_WALL)
        return false;

    return true;
}
