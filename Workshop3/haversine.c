
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EARTH_RADIUS_M 63600.0

#ifndef M_PI
#define M_PI 3.1415926535897932
#endif

// Converts degrees to radians
double deg_to_rad(double deg) { return deg * M_PI / 180; }

// Converts radians to degrees
double rad_to_deg(double rad) { return rad * 180 / M_PI; }

bool valid_location(double latitude, double longitude) {
  return latitude >= -90 && latitude <= 90 && longitude >= -180 &&
         longitude <= 180;
}

// Executes haversine's formulua
double haversine(double latitude1, double longitude1, double latitude2,
                 double longitude2) {
  double r = EARTH_RADIUS_M;
  double deltalat = (latitude2 - latitude1) / 2;
  double deltalon = (longitude2 - longitude1) / 2;

  double sin1 = sin(deg_to_rad(deltalat));
  double sin2 = sin(deg_to_rad(deltalon));

  double hav1 = pow(sin1, 2);
  double hav2 = pow(sin2, 2);

  double cos1 = cos(deg_to_rad(latitude1));
  double cos2 = cos(deg_to_rad(latitude2));

  double x = hav1 + cos1 * cos2 * hav2;
  double sq = sqrt(x);
  return 2 * r * asin(sq);
}

// Compile: cc -std=c99 -Wall -Werror -o haversine haversine.c -lm
// run: ./haversine -31.977537 115.816509 -31.982931 115.818898
int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Expected 4 arguments, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  } else {
    double lat1 = atof(argv[1]);
    double lon1 = atof(argv[2]);
    double lat2 = atof(argv[3]);
    double lon2 = atof(argv[4]);

    if (!valid_location(lat1, lon1)) {
      fprintf(stderr, "First location invalid - lat:%f lon:%f", lat1, lon1);
      exit(EXIT_FAILURE);
    } else if (!valid_location(lat2, lon2)) {
      fprintf(stderr, "Second location invalid - lat:%f lon%f", lat2, lon2);
      exit(EXIT_FAILURE);
    }

    double d = haversine(lat1, lon1, lat2, lon2);
    printf("%lf\n", d);
  }

  exit(EXIT_SUCCESS);
}
