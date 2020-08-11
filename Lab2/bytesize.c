#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int next_level(long val, const char *name) {
  if (val < 1000) {
    printf("%li%s\n", val, name);
    return -1;
  }
  return val / 1000;
}

#define check                                                                  \
  if (value == -1)                                                             \
    return;

void bytesize(long value) {
  value = next_level(value, "Byte");
  check value = next_level(value, "KByte");
  check value = next_level(value, "MByte");
  check printf("%liGByte\n", value);
  return;
}

int main(int argc, char *argv[]) {
  for (int arg = 1; arg < argc; arg++) {
    bytesize(atol(argv[arg]));
  }

  exit(EXIT_SUCCESS);
}
