#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Proper usage: wc [filename(s)]\n");
        return 1;
    }

    int line_count, // increments when we read an newline character
        word_count, // increments when we read a whitespace character 
        byte_count  // increments when we read a character
        = 0;

    int total_line_count,
        total_word_count,
        total_byte_count
        = 0;

    // TODO: fix word_count to be accurate
    for (int i = 1; i < argc; i++) {
      FILE *fptr;

      fptr = fopen(argv[i], "r");
      if (fptr == NULL) {
        perror("Error opening file\n");
        return 1;
      }

      char buffer[2];
      while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        char ch = buffer[0];
        if (ch == '\n') {
          line_count++;
        }
        if (ch == ' ') {
          word_count++;
        }
        byte_count++;
      }

      total_line_count += line_count;
      total_word_count += word_count;
      total_byte_count += byte_count;
      printf("%d %d %d %s\n", line_count, word_count, byte_count, argv[i]);
    }

    if (argc > 2) {
      printf("%d %d %d total\n", total_line_count, total_word_count, total_byte_count);
    }

    return 0;
}
