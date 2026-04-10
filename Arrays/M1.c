/***M1.** Take an array of 8 numbers. Separate and print even numbers and odd numbers:
```
Input:  {3, 8, 1, 6, 4, 9, 2, 7}
Evens:  8 6 4 2
Odds:   3 1 9 7*/

#include<stdio.h>

void EvenOddNumbers(int Input[],int Even[],int Odd[], int size){
        int ecount = 0;
        int ocount = 0;
    for(int i = 0; i<size ; i++) {

        if(Input[i]%2 == 0){
            Even[ecount] = Input [i];
            ecount++;
            
        }
        else{
            Odd[ocount] = Input[i];
            ocount++;
        }
       }

    for(int i= 0;i<ecount;i++){
    
    printf("%d  ",Even[i]);
           }
        }

int main(){

    int Input[8] = { 3,8,1,6,4,9,2,7};
    int Even[8] = {};
    int Odd[8] ={};
    int ecount;
    int ocount;
    EvenOddNumbers(Input,Even,Odd,8);

    
    return 0;

}