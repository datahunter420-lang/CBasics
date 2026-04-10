/*Take a string. Print only those characters whose frequency is exactly 1 (unique characters), in the order they appear.
Input:  "programming"
Output: p o a i n*/

#include <stdio.h>


void Unique_frequency(char string[]){

    for(int i = 0; string[i] != '\0'; i++){
            int is_unique = 1;
        for(int j = 0; j<i;j++){
            if(string[i]==string[j]){
                is_unique = 0;
                break;
            }
        }
        for(int j = i+1 ; string[j] != '\0';j++){
            if(string[i]==string[j]){
                is_unique = 0;
                break;
            }
        }


      if(is_unique){
        printf("%c",string[i]);


      }

    }
}

int main() {
    printf("Enter the string: ");
    char name[20];
    scanf("%s", name);
    Unique_frequency(name);
    return 0;
}