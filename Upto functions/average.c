#include <stdio.h>
int main(){
 int n,i,sum;
 printf("Enter the number you want the sum till there:\n");
 scanf("%d",&n);
 sum = 0;
 
 for(i=1;i<=n;i++){
  sum = i + sum; //accumulator pattern
}
 printf("The sum is : %d\n" ,sum);





 
 return 0;
}