#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compile this program with:
//      cc -std=c99 -Wall -Werror -o rotate rotate.c

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c, int r) {
  // Check if c is lower-case or not
  if (islower(c)) {
    // The ciphered character is ROT positions beyond c,
    // allowing for wrap-around
    return ('a' + (c - 'a' + r) % 26);
  } else if (isupper(c)) {
    return ('A' + (c - 'A' + r) % 26);
  } else {
    return c;
  }
}

//  Execution of the whole program begins at the main function

int main(int argcount, char *argvalue[]) {
  // Exit with an error if the number of arguments (including
  // the name of the executable) is not precisely 2
  if (argcount < 3) {
    fprintf(
        stderr,
        "%s: program expects at least 2 arguments, but instead received %d\n",
        argvalue[0], argcount - 1);
    exit(EXIT_FAILURE);
  } else {
    int rot = atoi(argvalue[1]);

    if (0 == rot) {
      // There's no error handling facilities on atoi (but will return 0 if
      // invalid)
      fprintf(stderr,
              "%s: first argument should be a rotation amount, but instead "
              "received %s\n",
              argvalue[0], argvalue[1]);
      exit(EXIT_FAILURE);
    }

    int arg;
    // Loop through every argument
    for (arg = 2; arg < argcount; arg++) {
      // Define a variable for a later loop
      int i;
      // Calculate the length of the first argument
      int length = strlen(argvalue[arg]);

      int temp_rot = atoi(argvalue[arg]);
      if (temp_rot != 0) {
        rot = temp_rot;
        continue;
      }

      FILE *fp = fopen(argvalue[arg], "r+");
      int j = 0;
      // fopen returns null if no file exists
      if (fp) {
        int c;

        while ((c = fgetc(fp)) != EOF && c != '\n') {
          printf("[%i] %c -> %c\n", j, c, rotate(c, rot));
          j++;
        }
        continue;
      }

      // Loop for every character in the text
      for (i = 0; i < length; i++) {
        // Determine and print the ciphered character
        printf("[%i] %c -> %c\n", i, argvalue[arg][i],
               rotate(argvalue[arg][i], rot));
      }

      // Print one final new-line character
      printf("\n");
    }
    // Exit indicating success
    exit(EXIT_SUCCESS);
  }
  return 0;
}
