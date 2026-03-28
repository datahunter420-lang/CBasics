//
//**P5.** Take N as input. Print factorial of N.
//*(factorial: 5! = 5×4×3×2×1 = 120)*

#include <stdio.h>

int main() {

    long long N;

    printf("Enter a number: ");
    scanf("%lld", &N);

    if (N < 0) {
        printf("Factorial undefined for negative numbers.\n");
        return 0;
    }

    long long result = 1;

    for (long long i = 1; i <= N; i++) {
        result = result * i;
    }

    printf("Factorial of %lld = %lld\n", N, result);

    return 0;
}
