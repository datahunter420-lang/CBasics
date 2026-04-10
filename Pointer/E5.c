#include <stdio.h>

void count_length(char *name);

int main() {
    char string[] = "Roshan";
    count_length(string);
    return 0;
}

void count_length(char *name){
    int count = 0;

    while(*name != '\0'){
        count++;     // count each character
        name++;      // move pointer forward
    }

    printf("The length of the string is %d\n", count);
}