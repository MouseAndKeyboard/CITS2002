#include "myCal.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_leap_year(int year) {
  if (year % 4 == 0) {

    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  }
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

/* day of week
 * ---
 * returns the current day of week (0 = Sun, ..., 6 = Sat)
 *
 * parameters
 * k = current day (1 to 31)
 * m = month (1 = march, ..., 10 = dec, 11 = jan, 12 = feb)
 * y = year */
int dow(int k, int m, int year) {
  // convert month into correct format
  m -= 2;
  if (0 == m) {
    --year;
    m = 12;
  } else if (-1 == m) {
    --year;
    m = 11;
  }

  // Get last 2 numbers of year
  int y = year % 100;
  // Get first 2 numbers of year
  int c = (year - y) / 100;

  // Perform the algorithm to calculate the day of month
  // https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
  return (k + (int)(2.6f * m - 0.2f) - 2 * c + y + (int)(y / 4.0f) +
          (int)(c / 4.0f)) %
         7;
}

#define N_DAYS_IN_WEEK 7
#define EPOCH_YEAR 1900

void print_month_cal(struct tm *tim) {
  // print out the current month and year
  char buff[40];
  strftime(buff, 40, "    %B %Y", tim);
  puts(buff);

  // print the days of the week
  puts("Su Mo Tu We Th Fr Sa");

  // Adjusts default tm struct values to be human readable
  int current_year = tim->tm_year + EPOCH_YEAR;
  // tm_mon is in [0,11] but we want [1, 12].
  int current_month = tim->tm_mon + 1;

  int starting_dow = dow(1, current_month, current_year);

  for (int i = 0; i < starting_dow; i++) {
    printf("   ");
  }

  int days = days_in_month(current_month, current_year);
  for (int day = 1; day <= days; day++) {

    if (day == tim->tm_mday) {
      printf("\033[7m");
    }

    // Add space padding to single numerals
    if (day < 10) {
      printf(" %i", day);
    } else {
      printf("%i", day);
    }

    printf("\033[0m ");

    // Ensure it wraps around every 7 days
    if (dow(day, current_month, current_year) == N_DAYS_IN_WEEK - 1) {
      printf("\n");
    }
  }
  printf("\n");
}
