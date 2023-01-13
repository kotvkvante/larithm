#ifndef LA_MAP_H
#define LA_MAP_H

#define MAP_SUBMAP_ELEMENT(map, submap, x, y) \
    (map)->submap[(map)->size_x * (y) + x]
#define MAP_ELEMENT(map, x, y) (map)->elements[(map)->size_x * (y) + (x)]
#define MAP_OBJECT(map, x, y) (map)->objects[(map)->size_x * (y) + (x)]

typedef struct la_map_template_t la_map_template_t;
typedef struct la_obj_character_t la_obj_character_t;
typedef struct la_obj_base_t la_obj_base_t;
typedef char la_map_collider_t;

typedef struct la_point_t
{
    int x, y;
} la_point_t;

typedef struct la_map_t
{
    int size_x, size_y;
    char* elements;

    // int obj_count;
    // int obj_arr_size;
    la_obj_base_t** objects;
    la_map_collider_t* colliders;

    la_obj_character_t* chrt;

    // int link_count;
    // la_link_t* links;

    int character_count;
    la_obj_character_t* characters;
} la_map_t;


la_map_t* map_new();
la_map_t* map_init();
la_map_t* map_init_from_template(la_map_template_t* tmpl);
// la_map_t* map_init_default();
// la_map_t* map_init_from_json_str(const char* str);
// la_map_t* map_init_from_file(const char* filename);

int map_is_on_map(la_map_t* map, int x, int y);

void map_add_character(la_map_t* map, la_obj_character_t* character);

void map_print(la_map_t* map);
void map_print_element(la_map_t* map, int x, int y);
void map_to_json_str(la_map_t* map, char* buffer, int buffer_size);
void map_to_json_file(la_map_t* map);


void map_close(la_map_t* map);

#endif /* end of include guard: LA_MAP_H */
