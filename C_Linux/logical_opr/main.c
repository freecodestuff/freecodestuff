#include<stdio.h>
int main() {
    int a = 5, b =2, c = 10;
    if ((a>b) && (a < c)) {
        printf("Logical AND\n");
    }
    if ((a >c) || (b<a)) {
        printf("Logical OR\n");
    }
    if(!(a == b)) {
        printf("Logical NOT\n");
    }
    return 0;
}