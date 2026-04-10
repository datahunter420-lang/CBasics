/* H1.** Take a 3×3 matrix as input. Print:
- The matrix itself
- Sum of each row
- Sum of diagonal elements (top-left to bottom-right)*/

#include<stdio.h>

void printMatrix(int Matrix[][3], int rows){

    printf("Enter the number row wise: \n");

    for ( int i = 0; i < rows; i++){
        for ( int j = 0; j < 3; j++){
            scanf("%d",&Matrix[i][j]);
        }
        printf("\n");
    }
    printf("The input matrix is: \n");

     for (int k = 0 ; k < 3; k++){
        for (int l = 0; l<3 ; l++){
         printf("%d ", Matrix[k][l]);
        }
        printf("\n");
        
    }
}

void SumofRows(int Matrix[][3], int rows){
    for(int i = 0 ; i < rows; i ++){
            int SUM = 0;
        for(int j = 0; j < 3 ; j++){
            SUM  = SUM + Matrix[i][j];
            if( j ==2){
            printf("The sum of row %d is %d\n", i+1, SUM );
            }

        }
    }


}

void SumofDiagonal(int Matrix[][3],int rows){
   int sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += Matrix[i][i];  // Only diagonal elements
    }
    printf("Sum of diagonal elements is %d\n", sum);
}



int main(){


    int Matrix[3][3] = {};
    printMatrix(Matrix, 3);
    SumofRows(Matrix, 3);
    SumofDiagonal(Matrix, 3);

    return 0;

    
}
