#include "pointers.h"

char *ptr_strcat(char *dest, const char *src) {

  // find the null byte on dest
  char byte;
  int pos = -1;
  do {
    pos++;
    byte = *(dest + pos);
  } while ('\0' != byte);

  // write over the dest until we
  // reach null byte on src
  int src_pos = -1;
  do {
    src_pos++;
    byte = *(src + src_pos);
    *(dest + pos) = byte;
    pos++;
  } while ('\0' != byte);

  return dest;
}

int ptr_strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int ptr_strncmp(const char *s1, const char *s2, size_t n) {
  for (int i = 0; i < n; i++) {
    if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return 0;
}
