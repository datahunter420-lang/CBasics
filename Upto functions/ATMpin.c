
/*8. Mini Challenge 🔥

ATM with Real Attempts
Build on your ATM PIN program. Now:

Give the user 3 attempts to enter the correct PIN (1234)
Each wrong attempt shows how many attempts remain
After 3 wrong attempts → "Card blocked."
Correct PIN at any attempt → "Access granted."*/

#include<stdio.h>

int main(){
int N;
printf("Enter the ATM pin number:  ");
scanf("%d",&N);

int PIN = 1234;
int cardblocked = 1;

for(int i =1; i<=3; i++){
    if(N==PIN){
        printf("ACCESS GRANTED\n");
        cardblocked = 0;
        break;
    }
    else {
       printf("WRONG PIN !! %d attempts is remaining\n", 3-i);
       if(i<3){
       printf("Enter the pin again: ");
       scanf("%d",&N);}
    }
}
if(cardblocked){
    printf("Card is blocked\n");
}
return 0;
}