#ifndef LA_MAP_TEMPLATE_H
#define LA_MAP_TEMPLATE_H


#define MAP_TMPL_ELEMENT(tmpl, x, y) (tmpl)->elements[(tmpl)->size_x * (y) + (x)]

#define LA_MAP_TEMPLATE_JSON "{\"type\":\"map\",\"size_x\":%d,\"size_y\":%d,\"elements\":%s}"
#define LA_MAP_TEMPLATE_BEAUTY_JSON "{\n\t\"type\":\"map\",\n\t\"size_x\":%d,\n\t\"size_y\":%d,\n\t\"elements\":%s\n}"

#define LA_MAP_TEMPLATE_FROZEN_JSON "{ type: %Q, size_x: %d, size_y: %d, elements: %M, links: %M }"
#define LA_MAP_TEMPLATE_TO_JSON(tmpl) \
    LA_MAP_TEMPLATE_FROZEN_JSON, \
    "map", tmpl->size_x, tmpl->size_y, \
    json_ex_printf_char_array, tmpl->elements, (size_t)(tmpl->size_x * tmpl->size_y)
#define LA_MAP_TEMPLATE_FROM_JSON(tmpl) \
    LA_MAP_TEMPLATE_FROZEN_JSON, \
    &type, &tmpl->size_x, &tmpl->size_y, \
    map_tmpl_scan_elements, (void*)(&tmpl->elements), \
    map_tmpl_scan_links, (void*)(&tmpl->links)

#define LA_MAP_TEMPLATE_HEADER_FROZEN_JSON \
    "{ type: %Q, size_x: %d, size_y: %d, lnk_count: %d }"
#define LA_MAP_TEMPLATE_BODY_FROZEN_JSON \
    "{ elements: %M, links: %M }"
#define LA_MAP_TEMPLATE_HEADER_FRON_JSON(tmpl) \
    LA_MAP_TEMPLATE_HEADER_FROZEN_JSON, \
    &type, \
    &tmpl->size_x, &tmpl->size_y, \
    &tmpl->size_lnks
#define LA_MAP_TEMPLATE_BODY_FROM_JSON(tmpl) \
    LA_MAP_TEMPLATE_BODY_FROZEN_JSON, \
    map_tmpl_scan_elements, (void*)(&tmpl), \
    map_tmpl_scan_links, (void*)(&tmpl)


typedef struct la_map_template_t
{
    int size_x, size_y;
    char* elements;

    int size_lnks;
    char* links;
} la_map_template_t;

la_map_template_t* map_tmpl_init(int size_x, int size_y);
la_map_template_t* map_tmpl_init_from_json_str(const char* str);
la_map_template_t* map_tmpl_init_from_file(const char* filename);

void map_tmpl_print(la_map_template_t* tmpl);

#endif /* end of include guard: LA_MAP_TEMPLATE_H */
