#include <stdlib.h>
#include <stdio.h>

// common
#include "la_types.h"
#include "la_solver.h"
#include "la_map.h"
#include "la_map_state.h"
#include "la_sequence.h"
#include "la_actions.h"

// common/objects
#include "character.h"

typedef la_action_ret_t (*la_action_f)(la_map_t*);

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
    la_action_ret_t res = 0;
    // la_map_state_t* map_state = map_state_init(map);
    for(int i = 0; i < sqnc->last; i++)
    {
        // printf("%d\n", sqnc->elements[i]);
        la_action_f action = resolver[sqnc->elements[i]];
        res = action(map);
        if(res == LA_ACTION_FAIL)
        {
            printf("0");
        }
        printf("1");

    }
    printf("\n");
    if(map_is_win(map))
    {
        printf("You Win!\n");
    }
    else
    {
        printf("Score = %d; Try again =(\n", map->score);
    }
}
