//**P4.** Take marks (0–100). Print grade as A/B/C/D/F using if-else chain.

#include <stdio.h>

int main(){
    int a;
   printf("Enter your marks:");
   scanf("%d",&a);

   if (a<=100){
      if(a>80){
      printf("You got A");
     }
      else if(a>70){
      printf("You got B");
     }
      else if(a>60){
      printf("You got C");
     }
      else if(a>50){
      printf("You got D");
      }
      else{
      printf("You got F");
      } 
   }
    else{
    printf("You entered wrong data");
   }
   return 0;

}