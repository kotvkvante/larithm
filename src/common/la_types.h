#ifndef LA_TYPES_H
#define LA_TYPES_H

typedef struct la_sequence_t
{
    int length;
    char* elements;
    char is_valid; // true, false, not stated
} la_sequence_t;

typedef struct la_map_t
{
    int size_x, size_y;
    char* elements;
} la_map_t;


#endif /* end of include guard: LA_TYPES_H */
