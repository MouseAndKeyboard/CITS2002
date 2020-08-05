#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compile this program with:
//      cc -std=c99 -Wall -Werror -o rotate rotate.c

#define ROT 3

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c) {
  // Check if c is lower-case or not
  if (islower(c)) {
    // The ciphered character is ROT positions beyond c,
    // allowing for wrap-around
    return ('a' + (c - 'a' + ROT) % 26);
  } else if (isupper(c)) {
    return ('A' + (c - 'A' + ROT) % 26);
  } else {
    return c;
  }
}

//  Execution of the whole program begins at the main function

int main(int argcount, char *argvalue[]) {
  // Exit with an error if the number of arguments (including
  // the name of the executable) is not precisely 2
  if (argcount < 2) {
    fprintf(
        stderr,
        "%s: program expects at least 1 argument, but instead received %d\n",
        argvalue[0], argcount - 1);
    exit(EXIT_FAILURE);
  } else {
    int arg;
    // Loop through every argument
    for (arg = 1; arg < argcount; arg++) {
      // Define a variable for a later loop
      int i;
      // Calculate the length of the first argument
      int length = strlen(argvalue[arg]);

      // Loop for every character in the text
      for (i = 0; i < length; i++) {
        // Determine and print the ciphered character
        printf("[%i] %c -> %c\n", i, argvalue[arg][i],
               rotate(argvalue[arg][i]));
      }

      // Print one final new-line character
      printf("\n");
    }
    // Exit indicating success
    exit(EXIT_SUCCESS);
  }
  return 0;
}
