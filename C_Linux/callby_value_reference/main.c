#include<stdio.h>

void add(int a, int b, int *z) {  // z is call by reference value
     *z = a+b;                    // a and b call by value
}
int main() {
     int c;
     add(10,20,&c);
     printf("%d \n",c);
     return 0;
}