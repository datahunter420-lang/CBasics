//find minmax from the array using pointers which returns more than one variable.
#include <stdio.h>
void minmax(int array[], int size,int *minVal , int *maxVal ){
         
    *minVal = array[0];
    *maxVal = array[0];
    for(int i = 1 ; i < size ; i++){
      if(array[i] < *minVal){
      *minVal = array[i];
      }
      if (array[i] > *maxVal){
        *maxVal = array[i];
      }
      }  
    }

int main() {
  int random_number[20] = {2,3,5,1,4,5,1,4,5,6,3,3,3,5,5,3,20,23,15,10};
  int minimum, maximum;
  minmax(random_number,20,&minimum,&maximum);
  printf("The maximum value is %d\n",maximum);
  printf("The minimum value is %d\n", minimum);
    return 0;
}