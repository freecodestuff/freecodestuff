#include<stdio.h>
int main() {
    int x = 5;
    printf("%d ", x++);
    printf("%d ", ++x);
    printf("%d ", x--);
    printf("%d \n", --x);
    return 0;
}