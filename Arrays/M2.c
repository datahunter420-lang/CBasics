/*M2.** Take N numbers into array. Search for a target number.
 Print its position if found, "Not found" otherwise.*/

#include<stdio.h>

void SearchTargetNumber(int N[], int size){
int target_found = 0;
int target_number;
printf(" Enter the target number: ");
scanf("%d", &target_number);

for(int i = 0; i< size; i++ ){
 if(target_number == N[i]){
    printf("Target number is found and it is in a position %d\n",i +1 );
    target_found = 1;
 }

 
}
if(target_found == 0){
    printf("Target not found");

}

}


int main(){
    int N[14] = {2,4,5,6,7,8,13,7,8,3,1,15,9,10};
    SearchTargetNumber(N, 14);
    return 0;
}

