#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s, <filename>\n", argv[0]);
        return 1;
    }

    FILE *funkyfile = fopen(argv[1], "r");

    if (funkyfile == NULL) {
        perror(argv[1]);
        return 1;
    }

    int count = 0;
    int is_in_word = 0;
    int curr_char = fgetc(funkyfile);

    while (curr_char != EOF) {
        if (!isspace(curr_char) && (is_in_word == 0)) {
            count++;
            is_in_word++;
        } else if (isspace(curr_char)) {
            is_in_word = 0;
        } else {
            is_in_word++;
        }
        curr_char = fgetc(funkyfile);
    }

    if (ferror(funkyfile)) {
        perror(argv[1]);
        fclose(funkyfile);
        return 1;
    }
    
    fclose(funkyfile);
    printf("The word count is %i.\n", count);
    return 0;
}