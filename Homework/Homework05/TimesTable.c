#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
static int numDigits(long value)
{
    int digits = 1;
    while (value >= 10) {
        value /= 10;
        digits++;
    }
    return digits;
}

static void printSeparator(int columns, int cellWidth)
{
    for (int c = 0; c < columns; c++) {
        putchar('+');
        for (int i = 0; i < cellWidth; i++) {
            putchar('-');
        }
    }
    puts("+");
}
 
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s N   (N must be an integer >= 2)\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *end;
    errno = 0;
    long n = strtol(argv[1], &end, 10);
    if (errno != 0 || *end != '\0' || end == argv[1]) {
        fprintf(stderr, "Error: '%s' is not a valid integer.\n", argv[1]);
        return EXIT_FAILURE;
    }
    if (n < 2) {
        fprintf(stderr, "Error: N must be at least 2.\n");
        return EXIT_FAILURE;
    }
    int valueWidth = numDigits(n * n);
    int cellWidth  = valueWidth + 2;
    int columns    = (int)(n - 1) + 1;  
    printSeparator(columns, cellWidth);
    printf("| %*s ", valueWidth, "x");
    for (long col = 2; col <= n; col++) {
        printf("| %*ld ", valueWidth, col);
    }
    puts("|");
    printSeparator(columns, cellWidth);
    for (long row = 2; row <= n; row++) {
        printf("| %*ld ", valueWidth, row);
        for (long col = 2; col <= n; col++) {
            printf("| %*ld ", valueWidth, row * col);
        }
        puts("|");
    }
    printSeparator(columns, cellWidth);
 
    return EXIT_SUCCESS;
}