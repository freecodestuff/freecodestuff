#include<stdio.h>
int add(int, int);         // Declaring function
int add(int a, int b) {   // definition of function
        return a+b;
}
int main() {
        int c;
        c = add(10,20);      // Function call
        printf("%d \n",c);
        return 0;
}