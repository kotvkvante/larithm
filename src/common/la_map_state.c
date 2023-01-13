#include <stdlib.h>
#include <stdio.h>

// common
#include "la_map.h"
#include "la_map_state.h"

// common/objects
#include "base.h"

// #include "character.h"

// owner must free map_state
la_map_state_t* map_state_init_with(la_map_t* map, la_obj_base_t* obj)
{
    la_map_state_t* map_state = malloc(sizeof(la_map_state_t));
    // map_state->current_character = 0;
    // map_state->character_pos.x = map->characters[0].x;
    // map_state->character_pos.y = map->characters[0].y;

    map_state->objects = malloc(sizeof(la_obj_base_t*) * map->size_x * map->size_y);
    for(int i; i < map->size_x * map->size_y; i++)
        map_state->objects[i] = obj;
    map_state->size_x = map->size_x;
    map_state->size_y = map->size_y;

    return map_state;
}

la_map_state_t* map_state_init(la_map_t* map)
{
    return map_state_init_with(map, NULL);
}




void map_state_add_obj()
{

}

void map_state_add_wall(la_map_state_t* map_state, la_obj_wall_t* wall)
{
    int x = ((la_obj_base_t*)wall)->x;
    int y = ((la_obj_base_t*)wall)->y;
    map_state->objects[x + map_state->size_x * y] = (la_obj_base_t*)wall;
}

void map_state_print(la_map_state_t* map_state)
{
    for(int i = 0; i < map_state->size_x; i++)
    {
        for(int j = 0; j < map_state->size_y; j++)
        {
            printf("%c", map_state->objects[i * map_state->size_x + j]->type);
        }
        printf("\n");
    }
}


void map_state_close(la_map_state_t* map_state)
{

}
