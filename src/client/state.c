#include <stdlib.h>
#include <stdio.h>

// client
#include "state.h"
// client/state
#include "menu.h"
extern clnt_state_t clnt_state_menu;
extern clnt_state_t clnt_state_game;

clnt_state_code_t clnt_current_state = CLNT_STATE_MENU;

clnt_state_t* states[CLNT_STATE_COUNT] =
{
    [CLNT_STATE_MENU] = &clnt_state_menu,
    [CLNT_STATE_GAME] = &clnt_state_game,
};

int clnt_is_valid_state(clnt_state_code_t code)
{
    return (0 < code) && (code < CLNT_STATE_COUNT);
}

void clnt_set_state(clnt_state_code_t code)
{
    if(!clnt_is_valid_state(code)) return;

    clnt_current_state = code;

}



clnt_state_code_t clnt_get_state()
{
    return clnt_current_state;
}
