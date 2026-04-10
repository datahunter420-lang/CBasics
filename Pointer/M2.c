//M2. Dynamically allocate an array of N integers (N taken from user).
// Fill it with squares (1, 4, 9, 16...). Print and free.

#include <stdio.h>
#include <stdlib.h>

int main() {
   int *arr = malloc(5*sizeof(int));
   printf("Enter the 5 numbers:\n");
   for(int i = 0 ; i < 5 ; i++){
    scanf("%d\n", &arr[i]);
   }
   printf("Squared numbered are:\n");

   for(int i = 0; i < 5; i++){
    *arr = arr[i] * arr [i];

    printf("%d",*arr);
   }
   free(arr);

    return 0;
}