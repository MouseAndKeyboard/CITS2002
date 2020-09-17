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

  printf("%i %i %i\n", res1, got, desired);

  return res1 || got != desired;
}

int test_ptr_strcmp(void) {
  char s1[30] = "hello world";
  char s2[35] = "hello world";
  int res1 = 0 != ptr_strcmp(s1, s2);
  char s3[10] = "Te57!ng";
  int desired = strcmp(s3, s1);
  int got = ptr_strcmp(s3, s1);

  printf("%i %i %i\n", res1, got, desired);

  return res1 || got != desired;
}

int test_ary_strncmp(void) {
  char s1[30] = "hello world";
  char s2[35] = "hello world";
  int res1 = 0 != ary_strncmp(s1, s2, 5);
  char s3[10] = "Te57!ng";
  int desired = strncmp(s3, s1, 40);
  int got = ary_strncmp(s3, s1, 40);

  char s4[10] = "Te57er";
  int desired2 = strncmp(s3, s4, 3);
  int got2 = ary_strncmp(s3, s4, 3);

  printf("%i %i %i, %i %i\n", res1, got, desired, got2, desired2);

  return res1 || got != desired;
}

int test_ptr_strncmp(void) {
  char s1[30] = "hello world";
  char s2[35] = "hello world";
  int res1 = 0 != ptr_strncmp(s1, s2, 5);
  char s3[10] = "Te57!ng";
  int desired = strncmp(s3, s1, 40);
  int got = ptr_strncmp(s3, s1, 40);

  char s4[10] = "Te57er";
  int desired2 = strncmp(s3, s4, 3);
  int got2 = ptr_strncmp(s3, s4, 3);

  printf("%i %i %i, %i %i\n", res1, got, desired, got2, desired2);

  return res1 || got != desired;
}

int test_ary_strchr(void) {
  char s1[20] = "hello world";
  char *des_1 = strchr(s1, 'l');
  char *des_2 = strchr(s1, 'h');
  char *des_3 = strchr(s1, 'd');
  char *des_4 = strchr(s1, 'z');

  char *got_1 = ary_strchr(s1, 'l');
  char *got_2 = ary_strchr(s1, 'h');
  char *got_3 = ary_strchr(s1, 'd');
  char *got_4 = ary_strchr(s1, 'z');

  printf("1) %s %s, 2) %s %s, 3) %s %s\n", des_1, got_1, des_2, got_2, des_3,
         got_3);

  return des_1 != got_1 || des_2 != got_2 || des_3 != got_3 || des_4 != got_4;
}

int test_ptr_strchr(void) {
  char s1[20] = "hello world";
  char *des_1 = strchr(s1, 'l');
  char *des_2 = strchr(s1, 'h');
  char *des_3 = strchr(s1, 'd');
  char *des_4 = strchr(s1, 'z');

  char *got_1 = ptr_strchr(s1, 'l');
  char *got_2 = ptr_strchr(s1, 'h');
  char *got_3 = ptr_strchr(s1, 'd');
  char *got_4 = ptr_strchr(s1, 'z');

  printf("1) %s %s, 2) %s %s, 3) %s %s, 4) %p %p\n", des_1, got_1, des_2, got_2,
         des_3, got_3, des_4, got_4);

  return strcmp(des_1, got_1) || strcmp(des_2, got_2) || strcmp(des_3, got_3) ||
         des_4 != NULL || got_4 != NULL;
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
  if (test_ptr_strcmp()) {
    exit(EXIT_FAILURE);
  }
  if (test_ary_strncmp()) {
    exit(EXIT_FAILURE);
  }
  if (test_ptr_strncmp()) {
    exit(EXIT_FAILURE);
  }
  if (test_ary_strchr()) {
    exit(EXIT_FAILURE);
  }
  if (test_ptr_strchr()) {
    exit(EXIT_FAILURE);
  }
}
