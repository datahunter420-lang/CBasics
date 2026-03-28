#include<stdio.h>
int main(){
 int N ;
 int sum = 0;
 while(N!=0){
    printf("Enter the number  : \n");
    scanf("%d",&N);
    sum = sum + N;

 }
printf("The sum of the number you entered is: %d\n ",sum);
return 0; 
}