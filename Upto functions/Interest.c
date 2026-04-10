#include <stdio.h>

int main(){
    int Principal, Time;
    float Rate, Interest;
    printf("ENter the Principal");
    scanf("%d",&Principal);
    printf("Enter the Time");
    scanf("%d",&Time);
    printf("Enter the Rate");
    scanf("%f",&Rate);
    Interest = (Principal * Time * Rate) /100;
    float I = Interest;
    printf("Interes is: %f", I);
    return 0;



}