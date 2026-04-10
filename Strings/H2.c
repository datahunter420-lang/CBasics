/* **H2.** Take a string. Count the frequency of each character that appears in it.
```
Input:  "hello"
Output: h=1, e=1, l=2, o=1  */

#include <stdio.h>
#include<string.h>


    void frequency_count(char string[], int length){



    for(int i = 0; string[i] != '\0'; i++){
        int flag = 0;
        int frequency = 0;
        char string1;
        int is_unique = 1;

        for(int j = 0 ; j< length ; j++){
            if(string[i]==string[j]){
                flag++;
                frequency = flag;
                string1 = string[i];
                is_unique = 0;
            }
        }
        if(!is_unique){
        
        printf("%c = %d\n" ,string1,frequency);
        }

    }


    }


int main() {

 printf("Enter the string: ");
 char name[20];
 scanf("%s",name);
 int len  = strlen(name);
 frequency_count(name,len);
    
    
    return 0;
}