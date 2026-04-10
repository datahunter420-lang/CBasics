//**E5.** Take two strings. Check if they are equal using `strcmp`. Print "Same" or "Different."

#include<stdio.h>
#include<string.h>
 int main(){

    char string1[] = "RoshanJaishi";
    char string2[] = "ComputerOfficer";

   int comparison = strcmp(string1,string2);
   printf("%d\n",comparison);
   if(comparison == 0)
    printf("Same");

   else
    printf("Different");
   
   
   
   return 0;
 }