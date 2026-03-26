/* ## 10. Mini Challenge 🔥

> **ATM PIN System**
> - Ask user to enter a PIN (integer)
> - If PIN == 1234 → show "Access granted. Balance: Rs. 50,000"
> - If PIN is between 1000–9999 but wrong → show "Wrong PIN. 2 attempts left."
> - If PIN is not even a 4-digit number → show "Invalid PIN format."
>
> *Think first: what conditions do you need? What order should you check them?*/

#include <stdio.h>

int main(){
    int pin;
    printf("Enter a pin number:\n");
    scanf("%d",&pin);
    if(pin>=1000 && pin<=9999){
        if(pin==1234){
            printf("Acess granted. Balance: Rs. 50,000\n");
        }
        else{
            printf("Wrong PIN. 2 attempts left.\n");
        }
    }
    else{
        printf("Invalid PIN format\n");
    }
    return 0;
}