
//P2.** Take two numbers. Print the larger one.

#include <stdio.h>

int main()

{   int a,b;  
    printf("Enter first number:\n");
    scanf("%d",&a);
    printf("Enter second number:\n");
    scanf("%d",&b);

    if(a>b){
        printf("%d is greater", a);
    }
    else{
        printf("%d is greater", b);
    }
}


