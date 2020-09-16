#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_arr_strcat(void) {

  char *dest = (char *)malloc(32);

  sprintf(dest, "hello");

  arr_strcat(dest, " world");

  return 0 != strcmp(dest, "hello world");
}

int main(void) { test_arr_strcat(); }
