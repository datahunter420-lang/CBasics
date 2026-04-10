/* **E3.** Take a string. Count how many vowels and consonants it has. */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){

    
    
    char word[] = "OfficerRoshan";
    int len  = strlen(word);
    
    int i = 0;
    int v_count = 0;
    while(word[i] != '\0'){
        char lower_case = tolower(word[i]);
        if(lower_case == 'a' || lower_case == 'e' || lower_case == 'i' || lower_case == 'o' || lower_case == 'u'){
            v_count++;
        }
        i++;
    }
    int consonant_count = len - v_count;
    printf(" The count of vowels is : %d and consonants is %d", v_count, consonant_count);


   return 0;  


}