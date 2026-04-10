/*#include<stdio.h>
int main(){

int N;
printf("Enter the number: ");
scanf("%d", &N);


int i;
int n;

for(i=1; i<=10;i++){
     n = N * i ;
   
    printf(" \n%d * %d = %d\n ", N, i, n);

}
return 0;
}*/

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