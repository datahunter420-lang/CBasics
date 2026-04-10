/* **E5.** Take two arrays of 3 elements each. Create a third array that is their element-wise sum.
```
a = {1,2,3}  b = {4,5,6}  →  c = {5,7,9} */

#include<stdio.h>

void AddArrays(int A[],int B[], int C[], int size){
    for(int i = 0; i < size; i++){
        C[i] =A[i] + B [i];
    }
}
int main(){
 
    int A[3] = {1,2,3};
    int B[3] = {4,5,6};
    int C[3] = {0};
    AB(A,B,C,3);
    printf("{ ");
    for(int j = 0;j<3;j++){

        printf(" %d, ", C[j]);

    }
    printf(" }");
    return 0;
}