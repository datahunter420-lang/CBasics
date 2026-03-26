// **P3.** Take three numbers. Print the largest of the three.

#include <stdio.h>

int main(){

    float x,y,z;
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    if(x>y && x>z){
        printf("%f is greater", x);
    }
    else if(y>x && y>z){
        printf("%f is greater", y);
    }
    else{
        printf("%f is greater", z);
    }
    
    return 0;
}