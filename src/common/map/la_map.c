#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

// extern
#include "frozen.h"

// common/map
#include "la_map.h"
#include "la_map_template.h"
#include "la_map_collider.h"

// common
#include "la_types.h"
#include "base.h"
#include "wall.h"
#include "character.h"
#include "door.h"
#include "levr.h"
#include "star.h"

#define FUNC(name) \
    static la_obj_base_t* _obj_ ## name ## _init(int x, int y) \
    { return (la_obj_base_t*)obj_ ## name ## _init(x, y); }
static la_obj_base_t* _obj_base_init(int x, int y) { return (la_obj_base_t*)obj_base_init(x, y); }
static la_obj_base_t* _obj_chrt_init(int x, int y) { return (la_obj_base_t*)obj_chrt_init(x, y); }
static la_obj_base_t* _obj_wall_init(int x, int y) { return (la_obj_base_t*)obj_wall_init(x, y); }
static la_obj_base_t* _obj_levr_init(int x, int y) { return (la_obj_base_t*)obj_levr_init(x, y); }
static la_obj_base_t* _obj_door_init(int x, int y) { return (la_obj_base_t*)obj_door_init(x, y); }
FUNC(star)

typedef la_obj_base_t* (*obj_init_f)(int x, int y);

static obj_init_f _map_resolver[] =
{
    [LA_OBJ_TYPE_BASE] = _obj_base_init,
    [LA_OBJ_TYPE_CHRT] = _obj_chrt_init,
    [LA_OBJ_TYPE_WALL] = _obj_wall_init,
    [LA_OBJ_TYPE_LEVR] = _obj_levr_init,
    [LA_OBJ_TYPE_DOOR] = _obj_door_init,
    [LA_OBJ_TYPE_STAR] = _obj_star_init,
};

la_map_t* map_new()
{
    return malloc(sizeof(la_map_t));
}

la_map_t* map_init_default()
{
    // la_map_t* map = map_new();
    // map->size_x = LA_DEFAULT_MAP_SIZE;
    // map->size_y = LA_DEFAULT_MAP_SIZE;
    // map->elements = malloc(sizeof(char) * map->size_x * map->size_y);
    // if(map->elements == NULL)
    // {
    //     printf("Cannot allocate memory!\n");
    // }
    // for(int k = 0; k < 16; k++) map->elements[k] = LA_DEFAULT_MAP4X4[k];
    //
    // return map;
}

la_map_t* map_init_from_template(la_map_template_t* tmpl)
{
    la_map_t* map = map_new();
    int s = tmpl->size_x * tmpl->size_y;
    map->size_x = tmpl->size_x;
    map->size_y = tmpl->size_y;
    map->objects = malloc(sizeof(la_obj_base_t*) * s);
    map_cldr_init(map);
    map_cldr_fill(map, 0);

    map->score = 0;
    map->score_count = 0;


    int id;
    for(int i = 0; i < s; i++)
    {
        id = (int)tmpl->elements[i];
        if (id == 0)
        {
            map->objects[i] = NULL;
        }
        else
        {
            obj_init_f obj_init = _map_resolver[id];
            int x = i % map->size_x;
            int y = i / map->size_y;
            la_obj_base_t* obj = obj_init(x, y);
            map->objects[i] = obj;
            switch (obj->type)
            {
                // TODO move this stuff to corresponding obj_init
                case LA_OBJ_TYPE_WALL:
                    map_cldr_set(map, x, y);
                    break;
                case LA_OBJ_TYPE_DOOR:
                    // obj_door_set((la_obj_door_t*)obj, x, y+1);
                    obj_door_map_sync((la_obj_door_t*)obj, map);

                    // map_cldr_set(map, x, y);
                    break;
                case LA_OBJ_TYPE_CHRT:
                    map->chrt = (la_obj_character_t*)obj;
                    break;
                case LA_OBJ_TYPE_LEVR:
                    int arr[] = {10, 1};
                    obj_levr_add_linked_arr((la_obj_levr_t*)obj, 2, arr);
                    // obj_levr_add_linked((la_obj_levr_t*)obj, 1);
                    break;
                case LA_OBJ_TYPE_STAR:
                    map->score_count++;
                    break;
                default:
                    break;
            }
        }
    }
    // for()
    // map->links = malloc(sizeof(la_link_t) * 1);
    // map->links[0].lnk_count = tmpl->links[0];
    // map->links[0].i = malloc(sizeof(int) * map->links[0].lnk_count);
    // map->links[0].i[0] = tmpl->links[1];
    // map->links[0].i[0] = tmpl->links[2];

    return map;
}

la_obj_base_t* map_get_obj_by_type(la_map_t* map, int x, int y, int type)
{
    la_obj_base_t* obj = MAP_OBJECT(map, x, y);
    // if( obj == NULL ) return NULL;
    while(obj != NULL)
    {
        if(obj->type == type) return obj;
        obj = obj->obj;
    }

    return NULL;
}


int map_is_on_map(la_map_t* map, int x, int y)
{
    return (0 <= x) && (x < map->size_x) && (0 <= y) && (y < map->size_y);
}

int map_is_win(la_map_t* map)
{
    return (map->score == map->score_count);
}

// static void map_scan_elements(const char* str, int len, void* user_data)
// {
//   struct json_token t;
//   char* arr = malloc(sizeof(char) * len);
//   for (int i = 0; json_scanf_array_elem(str, len, "", i, &t) > 0; i++) {
//       arr[i] = atoi(t.ptr);
//   }
//   (*(char**)user_data) = arr;
// }

// la_map_t* map_init_from_json_str(const char* str)
// {
//     char type[10];
//     la_map_t* map = malloc(sizeof(la_map_t));
//     json_scanf(str, strlen(str),
//       "{ type:%Q, size_x:%d, size_y:%d, elements:%M }",
//       &type, &map->size_x, &map->size_y, map_scan_elements, (void*)(&map->elements) );
//     return map;
// }

// la_map_t* map_init_from_file(const char* filename)
// {
//     char* str = json_fread(filename);
//     if(str == NULL)
//     {
//         printf("Error while reading file: %s\n", filename);
//         exit(-1);
//     }
//     return map_init_from_json_str((const char*)str);
// }

void map_print_element(la_map_t* map, int x, int y)
{
    printf("FUNCTION INCOMPLITE!\n");
    exit(-1);
    // printf("%d", MAP_ELEMENT(map, x, y)->texture);
}

void map_print(la_map_t* map)
{
    printf(">> Map: %d, %d\n", map->size_x, map->size_y);
    int n = 0;
    char c;
    char buffer[( map->size_x + 1) * ( map->size_y ) + 1];
    for (size_t i = 0; i < map->size_y; i++) {
        for (size_t j = 0; j < map->size_x; j++) {
            la_obj_base_t* obj = MAP_OBJECT(map, j, i);
            if( obj != NULL)
            {
                n += sprintf(buffer + n, "%c", obj->texture);
            }
            else
            {
                n += sprintf(buffer + n, "%c", '_');
            }
        }
        n += sprintf(buffer + n, "\n");
    }
    // buffer[( map->size_x + 1) * ( map->size_y )] = '\0';
    // for (size_t i = 0; i < map->obj_count; i++) {
    //     la_obj_base_t* obj = map->objects[i];
    //     buffer[ obj->x + obj->y * (map->size_x + 1) ] = obj->texture;
    // }

    fwrite(buffer, sizeof(char), n, stdout);
}

void map_print_obj_count(la_map_t* map)
{
    printf(">> Map obj count: %d, %d\n", map->size_x, map->size_y);
    int n = 0;
    char c;
    char buffer[( map->size_x + 1) * ( map->size_y ) + 1];
    for (size_t i = 0; i < map->size_y; i++) {
        for (size_t j = 0; j < map->size_x; j++) {
            la_obj_base_t* obj = MAP_OBJECT(map, j, i);
            int k = 0;
            while(obj!=NULL)
            {
                obj = obj->obj;
                k++;
            }
            n += sprintf(buffer+n ,"%d", k);
        }
        n += sprintf(buffer + n, "\n");
    }
    fwrite(buffer, sizeof(char), n, stdout);
}

#define LA_MAP_JSON_TEMPLATE "{\"type\":\"map\",\"size_x\":%d,\"size_y\":%d,\"elements\":%s}"
#define LA_MAP_BEAUTY_JSON_TEMPLATE "{\n\t\"type\":\"map\",\n\t\"size_x\":%d,\n\t\"size_y\":%d,\n\t\"elements\":%s\n}"
const char digits[] = "0123456789";

void map_to_json_str(la_map_t* map, char* buffer, int buffer_size)
{
    int product = map->size_x * map->size_y;
    int size = 2 * product - 1 + 2;
    char arr[size];

    arr[0] = '[';
    for (size_t i = 0; i < product; i++) {
        arr[1 + 2 * i]     = digits[map->elements[i]];
        arr[1 + 2 * i + 1] = ',';
    }
    arr[size - 1] = ']';
    arr[size] = '\0';

    snprintf(buffer, buffer_size,
        LA_MAP_JSON_TEMPLATE, map->size_x, map->size_y, arr);
}


// #define LA_MAP_FROZEN_JSON_TEMPLATE "{ type: %Q, size_x: %d, size_y: %d, elements: %M }"
// #define LA_MAP_TO_JSON(map) \
//     LA_MAP_FROZEN_JSON_TEMPLATE, \
//     "map", map->size_x, map->size_y, \
//     json_ex_printf_char_array, map->elements, (size_t)(map->size_x * map->size_y)
// void map_to_json_file(la_map_t* map)
// {
//     FILE* fp = fopen("map.json", "w");
//     struct json_out out2 = JSON_OUT_FILE(fp);
//     json_printf(&out2,
//         LA_MAP_TO_JSON(map)
//     );
// }

void map_inc_score(la_map_t* map)
{
    map->score++;
}

void map_dec_score(la_map_t* map)
{
    map->score--;
}


void map_add_obj(la_map_t* map, la_obj_base_t* obj)
{

    // map->objects[map->obj_count] = obj;
}


void map_close(la_map_t* map)
{
    if(map == NULL) return;
    free(map->elements);
    //free(map);
}
