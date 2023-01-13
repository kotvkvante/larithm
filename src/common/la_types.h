#ifndef LA_TYPES_H
#define LA_TYPES_H

typedef struct la_obj_character_t la_obj_character_t;

typedef struct la_point_t
{
    int x, y;
} la_point_t;

typedef struct la_link_t
{
    int color;
    la_point_t* points;
} la_link_t;

typedef struct la_map_t
{
    int size_x, size_y;
    char* elements;

    int link_count;
    la_link_t* links;

    int character_count;
    la_obj_character_t* characters;
} la_map_t;


#endif /* end of include guard: LA_TYPES_H */
