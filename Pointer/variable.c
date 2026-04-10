// swapping the variable value using pointers

#include <stdio.h>


void swap( int *p,int *q ){
   int temp;
   temp = *p;
   *p = *q;
   *q = temp;
   printf("The value of first number is %d\n",*p);
   printf("The value of second number is %d\n",*q );
}


int main() {
    printf("Enter the first number: ");
    int x;
    scanf("%d",&x);
    printf("Enter the second number: ");
    int y;
    scanf("%d",&y);
    printf("\n");
    swap(&x,&y);
    return 0;
}