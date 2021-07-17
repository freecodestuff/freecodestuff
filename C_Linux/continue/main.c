#include<stdio.h>
int main() {
    int a =0, i =0;
    do {
        i++;
       if (i == 3)
            continue;
       a = a+i;
       
    } while(i<5);
    printf("%d \n", a);
    return 0;
}