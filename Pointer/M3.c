// M3. Write a function that reverses an array in place using pointers — 

//two pointer technique  (one at start, one at end, swap and move toward center).

#include <stdio.h>
void reverse_array(int Array[],int size, int *p, int *q){
    for(int i = 0 ;p<q; i++){
        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;

  
    int Numbers[10]= {2,3,10,4,3,56,24,14,66,32,};
    int size = 10;
    reverse_array(Numbers, 10, Numbers, Numbers+9);
    for(int k = 0 ; k < size ; k++){
        printf("%d ",Numbers[k]);
        
    }
    return 0;
}