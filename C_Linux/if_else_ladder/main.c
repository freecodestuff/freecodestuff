#include<stdio.h>
int main() {
    int a = 10, b = 25, c = 20;
    if (a > b) 
       printf("a is greater than b\n");
    else if (c > b)
       printf("c is greater than b\n");

    else 
       printf("b is greater than a, c\n");
    return 0;
}