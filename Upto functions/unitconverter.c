#include <stdio.h>

int main() {
    int days, years, remaining_days, weeks;
    printf("Enter the number of days:");
    scanf("%d",&days);
    years =days/365;
    weeks = (days%365)/7;
    remaining_days = days - (years * 365) - (weeks * 7);
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Remaining Days: %d\n", remaining_days);
    return 0;
}