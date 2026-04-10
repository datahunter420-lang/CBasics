/*
**E2.** Take a string. Print its length without using `strlen` — count manually using a loop and `\0`.*/

#include<stdio.h>
int main(){

    char Name[] = "Roshanwillnotstop";
    int i = 0;
    while(Name[i]!='\0'){
        i++;
    }
    printf("The length of the character is : %d\n", i);
    return 0;
}