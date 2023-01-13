#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// extern
#include "frozen.h"
#include "frozen_ex.h"

#include "la_map_template.h"
#include "la_map_template_default.h"

static void map_tmpl_scan_elements(const char* str, int len, void* user_data)
{
  struct json_token t;
  char* arr = malloc(sizeof(char) * len);
  for (int i = 0; json_scanf_array_elem(str, len, "", i, &t) > 0; i++) {
      arr[i] = atoi(t.ptr);
  }
  (*(char**)user_data) = arr;
}

la_map_template_t* map_tmpl_new()
{
    return malloc(sizeof(la_map_template_t));
}

la_map_template_t* map_tmpl_init(int size_x, int size_y)
{
    la_map_template_t* tmpl = map_tmpl_new();
    int s = size_x * size_y;
    tmpl->size_x = size_x;
    tmpl->size_y = size_y;
    tmpl->elements = malloc(sizeof(char) * size_x * size_y);
    for(int i = 0; i < s; i++) tmpl->elements = 0;

    return tmpl;
}

la_map_template_t* map_tmpl_init_from_json_str(const char* str)
{
    la_map_template_t* tmpl = map_tmpl_new();
    char type[10];
    json_scanf(str, strlen(str),
      "{ type:%Q, size_x:%d, size_y:%d, elements:%M }",
      &type, &tmpl->size_x, &tmpl->size_y, map_tmpl_scan_elements, (void*)(&tmpl->elements) );

    return tmpl;
}

la_map_template_t* map_tmpl_init_from_file(const char* filename)
{
    char* str = json_fread(filename);
    if(str == NULL)
    {
        printf("Error while reading file: %s\n", filename);
        exit(-1);
    }
    la_map_template_t* tmpl = map_tmpl_init_from_json_str((const char*)str);
    free(str);

    return tmpl;
}


void map_tmpl_to_json_file(la_map_template_t* tmpl)
{
    FILE* fp = fopen("map.json", "w");
    struct json_out out2 = JSON_OUT_FILE(fp);
    json_printf(&out2,
        LA_MAP_TEMPLATE_TO_JSON(tmpl)
    );
}
