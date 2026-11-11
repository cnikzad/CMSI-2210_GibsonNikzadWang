#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
    printf("Please enter a number\n");
    return 1;
}

unsigned int number = strtoul(argv[1], NULL, 10);

for (int i = 31; i >= 0; i--) {
    printf("%u", (number >> i) & 1);
}

printf("\n");
return 0;

}