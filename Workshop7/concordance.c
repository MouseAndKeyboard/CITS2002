
#if defined(__linux__)
extern char *strdup(const char *str);
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x)                                                         \
  do {                                                                         \
  } while (0)
#endif

void error_quit(const char *msg) {
  fprintf(stderr, "[!] ERROR: %s\n", msg);
  exit(EXIT_FAILURE);
}

struct list {
  size_t count;
  size_t capacity;
  char **list;
};

void clean_list(struct list *list) { free(list->list); }

void add_item(struct list *wordlist, char *item) {
  size_t count = ++wordlist->count;

  if (count >= wordlist->capacity) {
    DEBUG_PRINT(("Old capacity: %lu New capacity: %lu", wordlist->capacity,
                 wordlist->capacity * 2));
    char **result =
        reallocarray(wordlist->list, wordlist->capacity * 2, sizeof(char *));
    if (!result) {
      clean_list(wordlist);
      error_quit("Failed to realloc");
    }
    wordlist->capacity *= 2;
  }

  strcpy(wordlist->list[wordlist->count - 1], item);
}

bool try_insert_word(struct list *wordlist, char *word) {
  int c = wordlist->count;
  for (int i = 0; i < c; i++) {
    if (strcmp(wordlist->list[i], word)) {
      // exists in there;
      DEBUG_PRINT(("Word already exists: %s\n", word));
      return false;
    }
  }

  add_item(wordlist, word);
  return true;
}

void print_list(struct list *list) {

  int c = list->count;

  DEBUG_PRINT(("%p->count = %lu\n", list, list->count));
  for (int i = 0; i < c; i++) {
    DEBUG_PRINT(("%ith\n", i));
    printf("%s\n", list->list[i]);
  }
}

struct list *create_wordlist(FILE *stream) {
  char line[BUFSIZ];
  struct list *wordlist = malloc(sizeof(struct list));
  wordlist->list = malloc(sizeof(char *));
  wordlist->capacity = sizeof(char *);

  DEBUG_PRINT(("Allocated wordlist\n"));

  while (fgets(line, BUFSIZ, stream)) {
    char *linecpy = line;

    // now to loop through every word in the line and add it
    while (*linecpy != '\0') {

      int wordlen = 0;
      char *wordstart = linecpy;
      while (*wordstart != '\0' && *wordstart != ' ') {
        wordlen++;
        linecpy++;
      }
      if (*linecpy == ' ') {
        linecpy++;
      }

      char word[BUFSIZ + 1];
      memset(word, 0, sizeof(word));
      if (wordlen) {
        strncpy(word, wordstart, wordlen);
        strncat(word, "\0", 1);
        try_insert_word(wordlist, word);
      }
    }
  }
  return wordlist;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error_quit("Requires only 2 arguments");
  }

  char *path = argv[1];
  FILE *stream = fopen(path, "r");
  if (!stream) {
    perror("[!] ERROR");
    exit(EXIT_FAILURE);
  }

  struct list *wl = create_wordlist(stream);
  print_list(wl);
  fclose(stream);
}
