#include "myCal.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_leap_year(int year) {
  // stub
  return false;
}

int days_in_month(int m, int y) {
  switch (m) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12: {
    return 31;
    break;
  }
  case 4:
  case 6:
  case 9:
  case 11: {
    return 30;
    break;
  }
  case 2: {
    // feb so need to check for leap year
    if (is_leap_year(y)) {
      return 29;
    } else {
      return 28;
    }
    break;
  }
  default: {
    fprintf(stderr, "%i is not a valid month", m);
    exit(EXIT_FAILURE);
  }
  }
}

void print_month_cal(struct tm *tim) {
  int current_year = tim->tm_year + 1900;
  int current_month = tim->tm_mon + 1;
  int days = days_in_month(current_month, current_year);

  // print the days of the week
  puts("Su Mo Tu We Th Fr Sa");

  for (int day = 1; day <= days; day++) {

    // Add space padding to single numerals
    if (day < 10) {
      printf(" %i ", day);
    } else {
      printf("%i ", day);
    }

    // Ensure it wraps around every 7 days
    if (day % 7 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}
