#include <stdio.h>

int main() {
    int n;
    int i;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number\n");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizz-buzz\n");
        }
        else if (i % 3 == 0) {
            printf("fizz\n");
        }
        else if (i % 5 == 0) {
            printf("buzz\n");
        }
        else {
            printf("%d\n", i);
        }
    }

    return 0;
}