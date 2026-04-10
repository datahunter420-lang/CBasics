// SUM of N numbers

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

/* long long contact;
printf("Enter the contact number:\n");
scanf("%lld",&contact);

while(contact > 9899999999LL|| contact < 9800000000LL ){
    printf("It is invalid! Try Again: \n\n");
    scanf("%lld",&contact);

}
printf("You entered: %lld", contact);

return 0;

}

*/
