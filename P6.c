
//P6.** Build a simple calculator using `switch`. Take two numbers and an operator (+, -, *, /). Print result. Handle division by zero.
#include<stdio.h>
int main(){
    printf("Welcome To the Simple Calculator........Press 1 = +,2 = - , 3 = *, 4 = /  \n\n ");

    float a,b;
    int answer;
    printf("Enter the first number: \n\n");
    scanf("%f",&a);
    printf("Enter the operator number \n\n");
    scanf("%d",&answer);
    printf("Enter the second number:\n\n ");
    scanf("%f",&b);
    float c = a+b;
    float d = a-b;
    float e = a*b;
    float f = a/b;
    switch(answer){
      case 1:
        printf("The answer is%f",c);
        break;
      case 2:
        printf("The answer is%f",d);
        break;
       case 3:
       printf("The answer is%f",e);
       break;
      case 4:
       if(b==0){
       printf("It is undefined");
    
       }
       else{
       printf("The answer is%f",f);
       }
       break;
      default:
         printf("Error");
       
          }
       
        




}    

