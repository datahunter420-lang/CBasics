//P8 (Hard).** Take a number 1–12. Using `switch` with deliberate fall-through, print which season it belongs to (Nepal seasons: Spring 3-4, Summer 5-6, Monsoon 7-9, Autumn 10-11, Winter 12-2).

#include <stdio.h>

int main(){

  int month;
  printf("Enter which month season you want to know:\n\n ");
  scanf(" %d", &month);


    switch(month){
        case 3:
        case 4:
        printf("It is Spring Season");
        break;
        case 5:
        case 6:
        printf("It is Summer Season");
        break;
        case 7:
        case 8:
        case 9:
        printf("It is Monsoon Season");
        break;
        case 10:
        case 11:
        printf("It is Autumn Season");
        break;
        case 12:
        case 1:
        case 2:
        printf("It is Winter Season");
        break;
        default:
        printf("Invalid! Enter a month between 1 and 12.\n");
    }
    return 0;
}

  

