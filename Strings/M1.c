//**M1.** Take a string. Reverse it manually using a loop (without `strrev`). Print the reversed string
#include <stdio.h>
#include<string.h>



void reverse_string(char ch[], int len){

    for(int i = 0 ; i < len / 2; i++){
     char temp = ch[i];// swap only half other will be automatically arranged in reverse order.
     ch[i] = ch[len - 1 - i];
     ch[len - 1 - i] = temp;
        
    }
         printf("%s",ch);

}


int main() {
    char String1[] = "Roshan";
    int len = strlen(String1);
    reverse_string(String1,len);

    return 0;
}