
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Converts degrees to radians
double deg_to_rad(double deg) { return deg * M_PI / 180; }

// Converts radians to degrees
double rad_to_deg(double rad) { return rad * 180 / M_PI; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Expected 2 arguments, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  printf("%f\n", rad_to_deg(deg_to_rad(180.0)));
}
