/**H1.** Take a string. Remove all duplicate characters, keeping only the first occurrence.
```
Input:  "programming"
Output: "progamin"*/

#include <stdio.h>
#include<string.h>

int main() {
   printf("enter the character: ");
   char string[20];
   scanf("%s",string);
    for(int i = 0 ; string[i] != '\0' ; i++ ){
         int is_unique = 1;
        for(int j = 0 ; j< i  ; j++){
            if(string[i]== string[j]){
              is_unique= 0;
              break;
            }
        }
                        
    if(is_unique){
      printf("%c",string[i]);
            }
    }
                

    return 0;
}