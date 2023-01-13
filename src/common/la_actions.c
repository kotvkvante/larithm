#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// common
#include "la_map.h"
#include "la_map_state.h"
#include "la_actions.h"

la_action_ret_t action_up(la_map_t* map, la_map_state_t* map_state)
{
    int x = map_state->character_pos.x;
    int y = map_state->character_pos.y;

    la_obj_character_t* chrt =
        (la_obj_character_t*)map_state->objects[x + y * map_state->size_x];
    // int chrt_is_valid_pos(
    //     la_obj_character_t* chrt, la_map_t* map, la_map_state_t* map_state,
    //     int x, int y)
    if(chrt_is_valid_pos(chrt, map, map_state, x, y) == true)
    {
        printf("Valid");
    }
    return LA_ACTION_OK;
}

la_action_ret_t action_down(la_map_t* map, la_map_state_t* map_state)
{
    return LA_ACTION_OK;
}

la_action_ret_t action_left(la_map_t* map, la_map_state_t* map_state)
{
    return LA_ACTION_OK;
}

la_action_ret_t action_rigth(la_map_t* map, la_map_state_t* map_state)
{
    return LA_ACTION_OK;
}

la_action_ret_t action_exec(la_map_t* map, la_map_state_t* map_state)
{
    return LA_ACTION_OK;
}
