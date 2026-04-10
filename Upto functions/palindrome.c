#include<stdio.h>
  int checkpalindrome(int N){
    int reverse = 0;
     while( N!= 0){
      int digit  = N % 10;
      reverse =(reverse * 10) + digit;
      N = N/10;
     }
     return reverse;
    }

  int main(){

    int x; 
    printf("Enter the number: \n");
    scanf("%d",&x);
    int y  = checkpalindrome(x);
    if(y==x){
        printf("It is palindrome.\n\n"); 
    }
    else{
        printf("It is not palindrome.\n\n");
        }

    return 0;
  }