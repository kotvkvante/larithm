#include <stdlib.h>
#include <stdio.h>

// common
#include "la_types.h"
#include "la_solver.h"
#include "la_map.h"
#include "la_map_state.h"
#include "la_sequence.h"
#include "la_actions.h"

typedef la_action_ret_t (*la_action_f)(la_map_t*, la_map_state_t*);

static la_action_f resolver[] =
{
    [LA_SQNC_ACTION_UP]    = action_up,
    [LA_SQNC_ACTION_DOWN]  = action_down,
    [LA_SQNC_ACTION_LEFT]  = action_left,
    [LA_SQNC_ACTION_RIGHT] = action_rigth,
    [LA_SQNC_ACTION_EXEC]  = action_exec
};

int la_solve(la_map_t* map, la_sequence_t* sqnc)
{
    la_action_ret_t ret = 0;
    la_map_state_t* map_state = map_state_init(map);
    for(int i = 0; i < sqnc->last; i++)
    {
        printf("%d\n", sqnc->elements[i]);
        la_action_f action = resolver[sqnc->elements[i]];
        ret = action(map, map_state);
        if(ret == LA_ACTION_FAIL)
        {
            printf("Action fail!");
        }
    }
}
