#include "arrays.h"

char *arr_strcat(char dest[], const char src[]) {

  // find the null byte on dest
  char byte;
  int pos = -1;
  do {
    pos++;
    byte = dest[pos];
  } while ('\0' != byte);

  // write over the dest until we
  // reach null byte on src
  int src_pos = -1;
  do {
    src_pos++;
    byte = src[src_pos];
    dest[pos] = byte;
    pos++;
  } while ('\0' != byte);

  return dest;
}

int ary_strcmp(const char s1[], const char s2[]) {
  int index = -1;
  char s1_c;
  char s2_c;
  do {
    index++;
    s1_c = s1[index];
    s2_c = s2[index];
  } while (s1_c != '\0' && s2_c != '\0' && s1_c == s2_c);

  return s1_c - s2_c;
}

int ary_strncmp(const char s1[], const char s2[], size_t n) {
  char s1_c;
  char s2_c;
  for (int i = 0; i < n; i++) {
    s1_c = s1[i];
    s2_c = s2[i];
    if (s1_c == '\0' || s2_c == '\0' || s1_c != s2_c) {
      return s1_c - s2_c;
    }
  }
  return 0;
}
