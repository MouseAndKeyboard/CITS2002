#ifndef __POINTERS_H_
#define __POINTERS_H_

#include <unistd.h>

char *ptr_strcat(char *dest, const char *src);
int ptr_strcmp(const char *s1, const char *s2);
int ptr_strncmp(const char *s1, const char *s2, size_t n);

#endif // __POINTERS_H_
