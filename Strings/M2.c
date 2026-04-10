//**M2.** Take a sentence with spaces using `fgets`. Count the number of words in it.

#include <stdio.h>
#include<string.h>

int main() {
     printf("Enter the sentence: ");
     char grinding[25];
     fgets(grinding ,25,stdin);
     int len  = strlen(grinding);
     int i = 0;
     int sum = 0;
    while(grinding[i] != '\0'){
         int flag = 0;
  
        if(grinding[i] == ' '){
            flag++;
            sum = sum + flag;
        }
       
     i++;
    }
    printf("The whitespace counts are: %d\n", sum);
    int count_words = len - sum;
    printf("The total words are: %d\n",count_words-1);




     
    return 0;
}