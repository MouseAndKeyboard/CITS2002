#ifndef __ARRAYS_H_
#define __ARRAYS_H_

#include <unistd.h>

/* Appends the src string to the dest string,
 * overwriting the terminating null byte ('\0')
 * at the end of dest, and then adds a terminating
 * null byte
 * The strings may not overlap,
 * and the dest string must have enough space for
 * the result.  If dest is not large enough, program
 * behavior  is  unpredictable
 * */
char *arr_strcat(char dest[], const char src[]);
int ary_strcmp(const char s1[], const char s2[]);
int ary_strncmp(const char s1[], const char s2[], size_t n);
char *ary_strchr(const char s[], int c);

#endif // __ARRAYS_H_
