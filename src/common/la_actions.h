#ifndef LA_ACTIONS_H
#define LA_ACTIONS_H

typedef enum {
    LA_ACTION_OK,
    LA_ACTION_FAIL,
} la_action_ret_t;

la_action_ret_t action_up(la_map_t* map);
la_action_ret_t action_down(la_map_t* map);
la_action_ret_t action_left(la_map_t* map);
la_action_ret_t action_rigth(la_map_t* map);
la_action_ret_t action_exec(la_map_t* map);

#endif /* end of include guard: LA_ACTIONS_H */
