#ifndef LA_MAP_COLLIDER_H
#define LA_MAP_COLLIDER_H

typedef struct la_map_t la_map_t;
typedef char la_map_collider_t;

void map_cldr_init(la_map_t* map);

void map_cldr_fill_default(la_map_t* map);
void map_cldr_fill(la_map_t* map, la_map_collider_t val);

void map_cldr_remove(la_map_t* map, int x, int y);
void map_cldr_set(la_map_t* map, int x, int y);
void map_cldr_print(la_map_t* map);

void map_cldr_close(la_map_t* map);

#endif /* end of include guard: LA_MAP_COLLIDER_H */
