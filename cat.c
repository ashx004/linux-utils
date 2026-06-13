#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fptr;

    if (argc < 2) {
        printf("Proper command usage: cat [filepath]\n");
        return 1;
    }

    fptr = fopen(argv[1], "r");

    if (fptr == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // largest buffer available on windows
    char buffer[4096];

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fptr);

    return 0;
}
