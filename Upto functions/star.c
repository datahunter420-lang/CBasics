/***P7.** Print this pattern:
```
*
**
***
****
******/

/* #include<stdio.h>
int main(){

        int i;
        int j;
        for ( i = 1; i<=5; i++){
            for(j=1;j<=i;j++){
                printf("*");
            }
          printf("\n");
        }

    }
        */

/*  * * * * *
    * * * *
    * * *
    * *
    *      */

#include<stdio.h>
int main(){

 for(int i=5;i>=1;i--){
    for(int j=1;j<=i;j++){
        printf("*");
    }
    printf("\n");
 }

 for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

}
