#include<stdio.h>
int (*fp)(int,int);    // fp is pointer to function
int add(int x, int y) {
        return x+y;
}

int sub(int x, int y) {
        return x-y;
}

int main() {
        int i;
        fp = add;              // Initializing fp with address add function
        i = (*fp)(10,20);      // Calling add function using fp
        printf("add: %d \n",i);
        fp = sub;
        i = (*fp)(20,10);
        printf("sub: %d \n",i);
        return 0;
}