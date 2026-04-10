// H1. Without using any string functions, write your own mystrcpy(char *dest, char *src) 
//that copies a string using pointer arithmetic only — no array indexing ([]).


#include <stdio.h>
#include <stdlib.h>

char mystrcpy(char *dest, char *src){

  while(*dest != 0){
    *dest  = *src;
    dest++;
    src++;
  }
*dest  = '\0';



  }



    
    
        
int main() {
    char string1[];
    char string2[] = "Jaishi";
    mystrcpy(string1, string2);
    printf("%s",string1);
   
    return 0;
}
