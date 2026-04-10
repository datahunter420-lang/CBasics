
/* M3.** Take 5 student marks. Sort them using bubble sort. Print ranks (1st = highest).*/

#include <stdio.h>

void Students_Ranks(int Marks[], int size){

    for(int i = 0;i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if(Marks[j]<Marks[j+1]){
                int temp  = Marks[j];
                Marks[j] = Marks [j+1];
                Marks[j+1] = temp;
            }


        }
    }
}

int main(){

    int Marks[5] = { 67,58,92,32,87};
    Students_Ranks(Marks, 5);
    for (int k = 0; k < 5 ; k++){
        printf("Rank %d: %d\n",k+1, Marks[k] );
    }
    return 0;
}