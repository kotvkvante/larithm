#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// extern
#include "frozen.h"

// common
#include "la_types.h"
#include "la_map.h"

const char LA_DEFAULT_MAP4X4[LA_DEFAULT_MAP_SIZE * LA_DEFAULT_MAP_SIZE] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 1, 1,
    1, 0, 0, 2,
};
const char LA_DEFAULT_MAP5X4[(LA_DEFAULT_MAP_SIZE+1) * LA_DEFAULT_MAP_SIZE] =
{
    0, 1, 0, 0, 0,
    0, 1, 1, 0, 0,
    0, 1, 1, 1, 1,
    1, 0, 0, 2, 2,
};

la_map_t* map_init_default()
{
    la_map_t* map = malloc(sizeof(la_map_t));
    map->size_x = LA_DEFAULT_MAP_SIZE;
    map->size_y = LA_DEFAULT_MAP_SIZE;
    map->elements = malloc(sizeof(char) * map->size_x * map->size_y);

    if(map->elements == NULL)
    {
        printf("Cannot allocate memory!\n");
    }
    int k = 0;
    for (size_t i = 0; i < map->size_x; i++) {
        for (size_t j = 0; j < map->size_y; j++) {
            map->elements[j + i * map->size_y] = LA_DEFAULT_MAP4X4[k];
            k++;
        }
    }
    return map;
}

static void map_scan_elements(const char* str, int len, void* user_data)
{
  struct json_token t;
  char* arr = malloc(sizeof(char) * len);
  for (int i = 0; json_scanf_array_elem(str, len, "", i, &t) > 0; i++) {
      arr[i] = atoi(t.ptr);
  }
  (*(char**)user_data) = arr;
}

la_map_t* map_init_from_json_str(const char* str)
{
    char type[10];
    la_map_t* map = malloc(sizeof(la_map_t));
    json_scanf(str, strlen(str),
      "{ type:%Q, size_x:%d, size_y:%d, elements:%M }",
      &type, &map->size_x, &map->size_y, map_scan_elements, (void*)(&map->elements) );
    return map;
}

la_map_t* map_init_from_file(const char* filename)
{
    char* str = json_fread(filename);
    if(str == NULL)
    {
        printf("Error while reading file: %s", filename);
        return NULL;
    }
    return map_init_from_json_str((const char*)str);
}

void map_print_element(la_map_t* map, int x, int y)
{
    printf("%d", MAP_ELEMENT(map, x, y));
}

void map_print(la_map_t* map)
{
    for (size_t i = 0; i < map->size_x; i++) {
        for (size_t j = 0; j < map->size_y; j++) {
            printf("%d", map->elements[j + i * map->size_y]);
        }
        printf("\n");
    }
    printf("\n");
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

#include "frozen_ex.h"

#define LA_MAP_FROZEN_JSON_TEMPLATE "{ type: %Q, size_x: %d, size_y: %d, elements: %M }"
#define LA_MAP_TO_JSON(map) \
    LA_MAP_FROZEN_JSON_TEMPLATE, \
    "map", map->size_x, map->size_y, \
    json_ex_printf_char_array, map->elements, (size_t)(map->size_x * map->size_y)
void map_to_json_file(la_map_t* map)
{
    FILE* fp = fopen("map.json", "w");
    struct json_out out2 = JSON_OUT_FILE(fp);
    json_printf(&out2,
        LA_MAP_TO_JSON(map)
    );
}

void map_close(la_map_t* map)
{
    if(map == NULL) return;
    free(map->elements);
    //free(map);
}
