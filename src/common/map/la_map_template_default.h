
#define LA_DEFAULT_MAP_SIZE 4

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
