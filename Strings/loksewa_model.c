/*  Given a string
 String S(“123456789”)
 Write a program in C++ that displays the following:
1
232
34543
4567654
567898765*/
#include <stdio.h>
#include<string.h>

int main() {
    
   char S[] = "12345678";
   int len  = strlen(S);
   


   for (int i = 0 ; i< 5 ;i++){

     for(int j = i; j < i+1 ; j++){
        S[i] = S[i] + S[j+i] +S[j-i];          
 

    }
    printf("%d\n",S[i]);

   }


    return 0;
}