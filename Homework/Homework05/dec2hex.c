#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
    printf("Please enter a number\n");
    return 1;
}

unsigned long long number = strtoull(argv[1], NULL, 10);

int digits = 8;

if (argc >= 3) {
    digits = atoi(argv[2]);
}

if (digits == 8) {
    printf("0x%08X\n", (unsigned int)number);
}
else if (digits == 16) {
    printf("0x%016llX\n", number);
}
else {
    printf("Digits must be 8 or 16\n");
    return 1;
}

printf("\n");
return 0;

}