#include<stdio.h>

int max (int a, int b){
    if(a>b){
        printf("%d is greater",a);
    }
    else{
        printf("%d is greater", b);
    }
    return 0;

}

int main(){
int x,y;
printf("Enter the first number: \n\n");
scanf("%d",&x);
printf("Enter the second number:  \n");
scanf("%d",&y);
max(x,y);
return 0;
}
