#include <stdlib.h>
#include <stdio.h>

#include "frozen/frozen.h"

int json_ex_printf_char_array(struct json_out *out, va_list *ap) {
    int len = 0;
    char *arr = va_arg(*ap, char*);
    size_t arr_size = va_arg(*ap, size_t);
    len += json_printf(out, "[", 1);
    for(int i = 0; i < arr_size; i++) {
        if (i > 0) len += json_printf(out, ", ");
        len += json_printf(out, "%d", arr[i]);
    }
    len += json_printf(out, "]", 1);
    return len;
}
// int json_printf_char_array(struct json_out *out, va_list *ap) {
//   int len = 0;
//   char *arr = va_arg(*ap, char *);
//   size_t i, arr_size = va_arg(*ap, size_t);
//   size_t elem_size = va_arg(*ap, size_t);
//   const char *fmt = va_arg(*ap, char *);
//   len += json_printf(out, "[", 1);
//   for (i = 0; arr != NULL && i < arr_size / elem_size; i++) {
//     union {
//       int64_t i;
//       double d;
//     } val;
//     memcpy(&val, arr + i * elem_size,
//            elem_size > sizeof(val) ? sizeof(val) : elem_size);
//     if (i > 0) len += json_printf(out, ", ");
//     if (strpbrk(fmt, "efg") != NULL) {
//       len += json_printf(out, fmt, val.d);
//     } else {
//       len += json_printf(out, fmt, val.i);
//     }
//   }
//   len += json_printf(out, "]", 1);
//   return len;
// }
