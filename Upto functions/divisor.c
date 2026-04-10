#include <stdio.h>

int main() {
    int N;
    printf("Enter the number\n");
    scanf("%d", &N);

    int isDivisible = 0;

    for (int i = 2; i <= 5; i++) {
        if (N % i == 0) {
            isDivisible = 1;
            break;
        }
    }

    if (isDivisible == 1) {
        printf("It is divisible\n");
    } else {
        printf("It is not divisible\n");
    }

    return 0;
}