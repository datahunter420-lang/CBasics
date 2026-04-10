#include<stdio.h>
int main()
{
int Array[] = {4,3,2,1,5,3,1,9};
int *p = & Array[0];
for(int i = 0; i < 8; i++){
printf(" %d\n",*p);
p++;
}
    return 0;
}