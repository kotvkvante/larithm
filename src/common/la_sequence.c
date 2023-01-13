#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// common
#include "la_sequence.h"

la_sequence_t* la_sqnc_init()
{
    la_sequence_t* sqnc = malloc(sizeof(la_sequence_t));

    sqnc->is_valid = NOT_STATED;
    sqnc->elements = NULL;
    sqnc->last     = 0;
    sqnc->length   = 0;

    return sqnc;
}

void la_sqnc_record(la_sequence_t* sqnc)
{
    if(sqnc->length == 0)
    {
        sqnc->length   = LA_SEQUENCE_DEFAULT_SIZE;
        sqnc->elements = malloc(sizeof(char) * LA_SEQUENCE_DEFAULT_SIZE);
    }
    if(sqnc->length == sqnc->last) // sqnc->length != 0
    {
        printf("Error: sequence full");
        return;
    }
    char e;

    printf("Enter sequence: ");
    do {
        e = getc(stdin);
        if(e == '\n') e = '0';
        sqnc->elements[sqnc->last] = e;
        sqnc->last++;
        if(sqnc->last == sqnc->length) break;
    } while(e != '0');

    return;
}

void la_sqnc_from_array(la_sequence_t* sqnc, int length, int* elements)
{
    sqnc->elements = malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++)
    {
        sqnc->elements[i] = elements[i];
    }
    sqnc->length = length;
    sqnc->last = length;
}

void la_sqnc_to_file(la_sequence_t* sqnc, const char* filename)
{
    FILE *fp;
    fp = fopen(filename,"w");
    if(fp == NULL)
    {
        printf("Error: can't open file %s\n", filename);
        return;
    }
    fprintf(fp, "%d\n%d\n%d\n",
        sqnc->length, sqnc->last, sqnc->is_valid
    );

    for (int i = 0; i < sqnc->last-1; i++)
    {
        fprintf(fp, "%d,", sqnc->elements[i]);
    }
    fprintf(fp, "%d", sqnc->elements[sqnc->last-1]);

    fclose (fp);
}
void la_sqnc_from_file(la_sequence_t* sqnc, const char* filename)
{
    FILE *fp;
    int n;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        printf("Error: can't open file %s\n", filename);
        return;
    }
    n = fscanf(fp, "%d\n%d\n%d\n",
        &sqnc->length, &sqnc->last, &sqnc->is_valid);

    sqnc->elements = malloc(sizeof(int) * sqnc->length);
    for (int i = 0; i < sqnc->last; i++)
    {
        fscanf(fp, "%d,", &sqnc->elements[i]);
    }

    // printf("FUNCTION NOT COMPLITE!");
    // exit(-1);
    // sqnc->is_valid = NOT_STATED;
    // sqnc->elements = NULL;
    // sqnc->last     = 0;
    // sqnc->length   = 0;

    fclose (fp);
}

void sqnc_print(la_sequence_t* sqnc)
{
    printf(">> Sequence: \n");
    char buffer[256];
    int n = 0;

    n += sprintf(buffer+n, "[");
    for(int i = 0; i < sqnc->last; i++)
    {
        n += sprintf(buffer+n, "%d,", sqnc->elements[i]);
        if(n >= 256)
        {
            printf("Buffer is full\n");
        }
    }
    n += sprintf(buffer+n-1, "]\n");
    fwrite(buffer, sizeof(char), n, stdout);
}

void sqnc_close(la_sequence_t* sqnc)
{
    free(sqnc->elements);
}
