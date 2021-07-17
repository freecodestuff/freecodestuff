#include<stdio.h>
int main() {
    int x = 2, y=10, z=-6;
    printf("%d %d %d %d %d %d\n",x&y,x|y,x<<2, y>>1,x^y,~z);
    return 0;
}