#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//  strdup() IS NOT A STANDARD C99 FUNCTION; WE NEED TO DECLARE IT UNDER LINUX
#if defined(__linux__)
extern char *strdup(const char *str);
#endif

//  WE STORE OUR CONCORDANCE AS 'AN ARRAY OF STRINGS'
//  words IS A 'POINTER TO A POINTER TO A CHARACTER'
//  words STORES THE ADDRESS OF THE BEGINNING OF AN ARRAY OF POINTERS TO chars,
//  EACH OF WHICH POINTS TO A char (AND ASSUMED TO BE THE START OF A STRING)
//  c.f.   https://i.stack.imgur.com/64Tgw.png
char **words = NULL;

int nwords = 0;

//  ITERATE THROUGH OUR CONCORDANCE, PRINTING EACH WORD (ONCE)
void print_words(void) {
  for (int w = 0; w < nwords; ++w) {
    printf("%s\n", words[w]);
  }
}

//  ADD A NEW WORD TO CONCORDANCE (PROVIDED THAT WE DON'T ALREADY HAVE IT)
void add_word(char newword[]) {
  //  COMPARE THIS NEW WORD WITH ALL KNOWN WORDS
  for (int w = 0; w < nwords; ++w) {
    if (strcmp(words[w], newword) == 0) { // we already have it
      return;
    }
  }

  //  GROW/EXTEND OUR CONCORDANCE BY ALLOCATING SPACE FOR ONE MORE POINTER
  //  THE AMOUNT OF EXISTING MEMORY (pointed to by words) IS INCREASED
  //  AND THE RESULTING 'NEW' POINTER IS SAVED BACK INTO THE SAME VARIABLE
  words = realloc(words, (nwords + 1) * sizeof(words[0]));

  //  SAVE A POINTER TO NEWLY ALLOCATED MEMORY HOLDING A CLONE/DUPLICATE OF WORD
  words[nwords] = strdup(newword);

  ++nwords;
}

//  BREAK A LINE OF TEXT INTO WORDS (SEQUENCES OF ALPHABETIC CHARACTERS)
void find_words(char *str) {
  int s = 0;

  //  PROCESS THE LINE (A STRING) UNTIL WE REACH THE TERMINATING NULL-BYTE
  while (*str != '\0') {
    char wrd[BUFSIZ];
    char *word = wrd;
    int w = 0;

    //  COLLECT SEQUENCES OF ALPHABETIC CHARACTER, COPYING THEM INTO word
    while (isalpha(*str)) {
      *(word + w) = *str;
      ++str;
      ++w;
      //  WE COULD ALSO WRITE:        word[w++] = str[s++];
    }

    //  DID WE COLLECT ANY CHARACTERS?
    if (w > 0) {
      *(word + w) = '\0'; // terminate our word (make it a string)
      printf("adding word %s\n", word);
      add_word(word);
    }

    //  SKIP ALL NON-ALPHABETIC CHARACTERS, ENSURE WE DON'T GO PAST END OF
    //  STRING
    while (*str != '\0' && !isalpha(*str)) {
      ++str;
    }
  }
}

//  READ THE INPUT TEXT - WE DON'T CARE HOW THE INPUT WAS PROVIDED
void read_input_text(FILE *fp) {
  char line[BUFSIZ];

  //  READ THE TEXT INPUT LINE-BY-LINE, UNTIL REACHING END-OF-FILE
  while (fgets(line, sizeof line, fp) != NULL) {
    find_words(line);
  }
}

int main(int argc, char *argv[]) {
  //  IF PROVIDED WITH A COMMAND-LINE ARGUMENT, ASSUME THAT IT'S A FILENAME
  if (argc > 1) {
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
      printf("Unable to open '%s'\n", argv[1]);
      exit(EXIT_FAILURE);
    }
    read_input_text(fp);
    fclose(fp); // we opened it, so we close it
  }
  //  OTHERWISE READ INPUT FROM STANDARD-INPUT STREAM (a pipe or redirected
  //  file)
  else {
    read_input_text(stdin);
  }

  print_words();
  exit(EXIT_SUCCESS);
  return 0;
}
