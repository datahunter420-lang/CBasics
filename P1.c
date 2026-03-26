// P1.** Take a number. Print whether it is positive, negative, or zero.

#include <stdio.h>

 int main() {

    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);
    if(num>0){
      printf("It is positive number");
    }
    else if(num<0){
       printf("It is negative number");
    }
    else{
      printf("It is zero"); 
   }
          }
   
 