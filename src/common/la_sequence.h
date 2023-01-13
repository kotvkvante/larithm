#ifndef LA_SEQUENCE_H
#define LA_SEQUENCE_H

#define LA_SEQUENCE_DEFAULT_SIZE 16

typedef enum {TRUE, FALSE, NOT_STATED} la_sqnc_state_t;

typedef enum {
    LA_SQNC_ACTION_UP,
    LA_SQNC_ACTION_DOWN,
    LA_SQNC_ACTION_LEFT,
    LA_SQNC_ACTION_RIGHT,
    LA_SQNC_ACTION_EXEC,
    LA_SQNC_ACTION_COUNT
} la_sequence_action_t;


typedef struct la_sequence_t
{
    int length;
    int last;
    // char* elements;
    int* elements;
    char is_valid; // true, false, not stated
} la_sequence_t;

la_sequence_t* la_sqnc_init();
void la_sqnc_record(la_sequence_t* sqnc);
void la_sqnc_to_file(la_sequence_t* sqnc, const char* filename);
void la_sqnc_from_file(la_sequence_t* sqnc, const char* filename);
void la_sqnc_from_array(la_sequence_t* sqnc, int length, int* elements);

void sqnc_print(la_sequence_t* sqnc);

void sqnc_close(la_sequence_t* sqnc);

#endif /* end of include guard: LA_SEQUENCE_H */
