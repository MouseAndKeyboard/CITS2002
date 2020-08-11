#include <stdio.h>
#include <stdlib.h>

char *ordinal_suffix(int number) {
  if (number == 11 || number == 12 || number == 13) {
    return "th";
  }

  switch (number % 10) {
  case 1: {
    return "st";
    break;
  }
  case 2: {
    return "nd";
    break;
  }
  case 3: {
    return "rd";
    break;
  }
  default: {
    return "th";
    break;
  }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("Expected at least 1 argument.");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    printf("%s%s\n", argv[i], ordinal_suffix(atoi(argv[i])));
  }
}
