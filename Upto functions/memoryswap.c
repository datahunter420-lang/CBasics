#include <stdio.h>
//The Memory Swap: Declare two integers, a and b. Use scanf to take their values from the user. Swap their values using a third temporary variable and print the result


int main() {
    int a,b;
    printf("Enter the first value:\n" );
    scanf("%d",&a);
    printf("Enter the second value:\n");
    scanf("%d",&b);
    
    int temp;

    temp = b;
    b = a;
    a = temp;
    printf("Swap numbers are:%d\n\n",a);
    printf("Swap numbers are:%d\n\n",b);

    return 0;
}