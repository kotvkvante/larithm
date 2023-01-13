#ifndef LA_BASE_H
#define LA_BASE_H

#define LA_OBJ_TYPE_BASE 0
#define LA_OBJ_TYPE_CHRT 1
#define LA_OBJ_TYPE_WALL 2

typedef char la_texture_t;

typedef struct la_sprite_t
{
    int count;
    int current;
    la_texture_t* texture;
} la_sprite_t;

typedef struct la_obj_base_t
{
    char type;
    int x, y;
    union {
        la_sprite_t sprite;
        la_texture_t texture;
    };

    struct la_obj_base_t* obj;

} la_obj_base_t;

la_obj_base_t* obj_base_new();
la_obj_base_t* obj_base_init(int x, int y);
void obj_base_init_xy(la_obj_base_t* base, int x, int y);
void obj_base_init_xyt(la_obj_base_t* base, int x, int y, int type);

#endif /* end of include guard: LA_BASE_H */
