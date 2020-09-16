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
