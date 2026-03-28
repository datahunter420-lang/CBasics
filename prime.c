#include <stdio.h>

int main() {
    int N;
    printf("Enter the number: ");
    scanf("%d", &N);

    // Step 1: Handle edge case
    if (N < 2) {
        printf("Not Prime");
        return 0;
    }

    int isPrime = 1;   // assume number is prime

    // Step 2: Check divisibility
    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            isPrime = 0;   // found a divisor
            break;         // stop checking
        }
    }

    // Step 3: Print result once
    if (isPrime == 1) {
        printf("Prime");
    } else {
        printf("Not Prime");
    }

    return 0;
}