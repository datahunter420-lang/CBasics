/* **E4.** Take a string. Convert it to uppercase manually using a loop — without `strupr`. *(Hint: 'a' - 'A' = 32 in ASCII)* */
#include<stdio.h>
int main(){


    char  my_name[] = "RosHAnjAiShi";
    char adder = ' ';
    char new_name[20];
    for(int i = 0 ; my_name[i] != '\0'; i++){
        if( 96< my_name[i] && my_name[i] < 123){
         my_name[i] =my_name[i] - adder ;
         printf("%c",my_name[i]);
        }
        else{
        printf("%c",my_name[i]);
        }
        
    }
return  0; 
 
}