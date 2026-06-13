#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Proper usage: wc [filename(s)]\n");
        return 1;
    }

    int total_line_count,
        total_word_count,
        total_byte_count
        = 0;

    for (int i = 1; i < argc; i++) {
      int line_count, // increment when a newline character is read
          word_count, // increment when we have exited a word
          byte_count, // increment when we read a character
          in_word     // toggle to see if we are in a word or not 
          = 0;

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

        if (ch == ' ' || ch == '\n' || ch == '\t') {
          in_word = 0;
        }
        else if (!in_word) {
          in_word = 1;
          word_count++;
        }

        byte_count++;
      }

      total_line_count += line_count;
      total_word_count += word_count;
      total_byte_count += byte_count;
      printf("%d %d %d %s\n", line_count, word_count, byte_count, argv[i]);
    }

    // print count for all files passed in
    if (argc > 2) {
      printf("%d %d %d total\n", total_line_count, total_word_count, total_byte_count);
    }

    return 0;
}
