#include<stdio.h>
int main() {
    int a =0, i =0;
    do {
       if (i == 3)
            break;
       a = a+i;
       i++;
    } while(i<5);
    printf("%d \n", a);
    return 0;
}