#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void money(int total, int *dollars, int *cents) {
  *dollars = total / 100;
  *cents = total % 100;
  return;
}

int main(int argc, char *argv[]) {

  int total = 524;
  int dollars;
  int cents;

  money(total, &dollars, &cents);

  printf("%i -> %i dollars and %i cents\n", total, dollars, cents);

  return EXIT_SUCCESS;
}
