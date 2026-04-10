//E2. Write a function square(int *n) that squares the number in place 
//— modifying the original variable using a pointer.

/* #include <stdio.h>
void square( int *n, int y);

int main() {
    int number;
    printf("Enter the number:");
    scanf("%d",&number);
    square(&number,number);
    printf("The modified number is : %d", number);

    
    return 0;
}
void square(int *n, int y){
    *n  =  y * y;
    


}*/

#include <stdio.h>

void square(int *n);

int main() {
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);

    square(&number);

    printf("The modified number is: %d", number);
    return 0;
}

void square(int *n) {
    *n = (*n) * (*n);
}