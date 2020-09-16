#include "arrays.h"
#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_arr_strcat(void) {
  char dest[32];
  sprintf(dest, "hello");
  puts(arr_strcat(dest, " world"));
  int res = 0 != strcmp(dest, "hello world");
  return res;
}

int test_ptr_strcat(void) {
  char *dest = (char *)malloc(32);
  sprintf(dest, "hello");
  puts(ptr_strcat(dest, " world"));
  int res = 0 != strcmp(dest, "hello world");
  free(dest);
  return res;
}

int test_arr_strcmp(void) {
  char s1[30] = "hello world";
  char s2[35] = "hello world";
  int res1 = 0 != ary_strcmp(s1, s2);

  char s3[10] = "Te57!ng";
  int desired = strcmp(s3, s1);
  int got = ary_strcmp(s3, s1);

  return res1 || got != desired;
}

int main(void) {
  if (test_arr_strcat()) {
    exit(EXIT_FAILURE);
  }
  if (test_ptr_strcat()) {
    exit(EXIT_FAILURE);
  }
  if (test_arr_strcmp()) {
    exit(EXIT_FAILURE);
  }
}
