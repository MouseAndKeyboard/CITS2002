#include "myCal.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  time_t t = time(NULL);
  struct tm tim = *localtime(&t);
  print_month_cal(&tim);
  return EXIT_SUCCESS;
}
