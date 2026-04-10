/*
**P5.** Take a year as input. Print whether it's a leap year.
*(Leap year: divisible by 4, but if divisible by 100 then also by 400)*/

#include <stdio.h>
int main(){

    int year,year1,year2,year3;
    scanf("%d",&year);
    year1 = year%4;
    year2 = year%100;
    year3 = year%400;

    if(year2==0){
        if(year3==0)
        printf("It is leap year");
    }
    else if(year1==0){
        printf("It is leap year");
    }
    else{
        printf("It is not leap year");
    }
    return 0;


}