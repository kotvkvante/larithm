#ifndef LA_BASE_H
#define LA_BASE_H

typedef struct la_texture_t
{
    int i;
} la_texture_t;

typedef struct la_sprite_t
{
    int count;
    int current;
    la_texture_t* texture;
} la_sprite_t;

#define LA_OBJ_TYPE_BASE '_'
typedef struct la_obj_base_t
{
    char type;
    int x, y;
    la_sprite_t sprite;
} la_obj_base_t;

la_obj_base_t* obj_base_new();
void obj_base_init_xy(la_obj_base_t* base, int x, int y);




#endif /* end of include guard: LA_BASE_H */
