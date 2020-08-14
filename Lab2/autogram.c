#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* numbers[] = {
	"zero", "one", "two", "three", "four", "five", "six",
	"seven", "eight", "nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen", "twenty", "twenty-one", "twenty-two", "twenty-three", "twenty-four",
	"twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine",
	"thirty", "thirty-one", "thirty-two", "thirty-three", "thirty-four",
	"thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine",
	"forty", "forty-one", "forty-two", "forty-three", "forty-four",
	"forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine",
	"fifty", "fifty-one", "fifty-two", "fifty-three", "fifty-four",
	"fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine",
	"sixty", "sixty-one", "sixty-two", "sixty-three", "sixty-four",
	"sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine",
	"seventy", "seventy-one", "seventy-two", "seventy-three", "seventy-four",
	"seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine",
	"eighty", "eighty-one", "eighty-two", "eighty-three", "eighty-four",
	"eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine",
	"ninety", "ninety-one", "ninety-two", "ninety-three", "ninety-four",
	"ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine",
}


void count_characters(char *string, int *char_counts) {
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    char lower = tolower(string[i]);
    char_counts[lower - 'a']++;
  }
}

int get_number_len(int number) {
  if (number < 14) {
  }
}

int number_word_count(int c, int *letter_counts) {
  // this should adjust letter counts to count the
  // number of letters it would take to express letter counts
  if (letter_counts) {
  }
}

void autograms(char *seed) {

  int char_counts[26];
  for (int i = 0; i < 26; i++) {
    char_counts[i] = 0;
  }

  count_characters(seed, char_counts);
  for (int x = 0; x < 26; x++) {
    printf("%i\n", char_counts[x]);
  }
}

int main() {
  // an autogram needs a seed word.
  autograms("autogram");
}
