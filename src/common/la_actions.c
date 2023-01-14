#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// common
#include "la_map.h"
#include "la_map_state.h"
#include "la_actions.h"
// common/objects
#include "character.h"
#include "levr.h"

la_action_ret_t action_up(la_map_t* map)
{
    int res = chrt_move_dxdy(map->chrt, map, 0, 1);
    if(res == false) return LA_ACTION_FAIL;
    return LA_ACTION_OK;
}

la_action_ret_t action_down(la_map_t* map)
{
    int res = chrt_move_dxdy(map->chrt, map, 0, -1);
    if(res == false) return LA_ACTION_FAIL;
    return LA_ACTION_OK;
}

la_action_ret_t action_left(la_map_t* map)
{
    int res = chrt_move_dxdy(map->chrt, map, -1, 0);
    if(res == false) return LA_ACTION_FAIL;
    return LA_ACTION_OK;
}

la_action_ret_t action_rigth(la_map_t* map)
{
    int res = chrt_move_dxdy(map->chrt, map, 1, 0);
    if(res == false) return LA_ACTION_FAIL;
    return LA_ACTION_OK;
}

la_action_ret_t action_exec(la_map_t* map)
{
    la_obj_base_t* obj = MAP_OBJECT(map, map->chrt->x, map->chrt->y);
    int res = true;
    if(obj == NULL) return LA_ACTION_FAIL;

    while(obj != NULL)
    {
        switch (obj->type)
        {
            case LA_OBJ_TYPE_LEVR:
                res = res && obj_levr_press((la_obj_levr_t*)obj, map);
                break;
            default:
                break;
        }
        obj = obj->obj;
    }
    if(res == false)
        return LA_ACTION_FAIL;
    return LA_ACTION_OK;
}
