#include <stdlib.h>
#include <stdio.h>
#include "la_map.h"
#include "la_map_collider.h"

void map_cldr_init(la_map_t* map)
{
    int s = map->size_x * map->size_y;
    map->colliders = malloc(sizeof(la_map_collider_t) * s);
}

void map_cldr_fill_default(la_map_t* map)
{
    map_cldr_fill(map, 0);
    map_cldr_set(map, 1, 1);
    map_cldr_set(map, 0, 2);
}

void map_cldr_fill(la_map_t* map, la_map_collider_t val)
{
    int s = map->size_x * map->size_y;
    for (size_t i = 0; i < s; i++) {
        map->colliders[i] = val;
    }
}

void map_cldr_init_default(la_map_t* map)
{

}

void map_cldr_switch(la_map_t* map, int x, int y)
{
    MAP_SUBMAP_ELEMENT(map, colliders, x, y) = !(MAP_SUBMAP_ELEMENT(map, colliders, x, y));
}

void map_cldr_set(la_map_t* map, int x, int y)
{
    MAP_SUBMAP_ELEMENT(map, colliders, x, y) = 1;
}
void map_cldr_remove(la_map_t* map, int x, int y)
{
    MAP_SUBMAP_ELEMENT(map, colliders, x, y) = 0;
}

void map_cldr_print(la_map_t* map)
{
    printf(">> Map Colliders: \n");
    for (size_t j = 0; j < map->size_y; j++) {
        for (size_t i = 0; i < map->size_x; i++) {
            printf("%d", (int)MAP_SUBMAP_ELEMENT(map, colliders, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

void map_cldr_close(la_map_t* map)
{
    free(map->colliders);
}
