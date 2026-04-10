#include <stdio.h>

int main() {
    int x = 10;
    int *p  = &x;


    printf("value of x is : %d\n",x);
    printf("address of x is : %d\n", &x);
    printf("value of x is : %d\n", *p);
    printf("address of p  is : %d\n", &p);
    
    *p = 100;
    printf("the new value of x is %d\n", *p );

    return 0;
}