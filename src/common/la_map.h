#ifndef LA_MAP_H
#define LA_MAP_H

#define MAP_ELEMENT(map, x, y) (map)->elements[(map)->size_x * (y) + (x)]
#define LA_DEFAULT_MAP_SIZE 4

typedef struct la_map_t la_map_t;

la_map_t* map_init();
la_map_t* map_init_default();
la_map_t* map_init_from_json_str(const char* str);
la_map_t* map_init_from_file(const char* filename);

void map_print(la_map_t* map);
void map_print_element(la_map_t* map, int x, int y);
void map_to_json_str(la_map_t* map, char* buffer, int buffer_size);
void map_to_json_file(la_map_t* map);

void map_close(la_map_t* map);



#endif /* end of include guard: LA_MAP_H */
