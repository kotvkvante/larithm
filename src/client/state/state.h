#ifndef STATE_H
#define STATE_H

typedef enum {
    CLNT_STATE_MENU,
    CLNT_STATE_GAME,
    CLNT_STATE_PAUSE,
    CLNT_STATE_COUNT,
} clnt_state_code_t;

typedef void (*render_frame_f)(void* ctx);


typedef struct clnt_state_t
{
    int clnt_state_code_t;
    render_frame_f render_frame;

    // render;

} clnt_state_t;

#endif /* end of include guard: STATE_H */
