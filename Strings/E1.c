/* **E1.** Take a string input. Print it character by character using a loop, each on a new line. */

#include<stdio.h>

int main(){

    printf("Enter a character: ");
    char Name[10];
    scanf("%s",Name);
    int i = 0;
    while(Name[i]!=0){
        printf("%c\n", Name[i]);
        i++;
    }
    
return 0;
}