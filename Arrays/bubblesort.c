#include<stdio.h>


void bubblesort(int Array[], int size){
 for(int i= 0;i<size -1 ;i++){
    for(int j = 0;j<size -1 -i ;j++){
        if (Array[j]>Array[j+1]){
            int temp;
            temp = Array[j];
            Array[j]= Array[j+1];
            Array[j+1] = temp;
        }

    }
}
}

int main(){

int Array[6] = {1,5,2,4,6,3};
bubblesort(Array, 6);
for(int k = 0 ; k < 6; k++){
    printf("The sorted number are : %d", Array[k]);
    printf("\n");
}
return 0;

}