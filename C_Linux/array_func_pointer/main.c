#include<stdio.h>
int (*fp[2])(int,int);      // fp is array of 2 pointer to functions
int add(int x, int y) {
	return x+y;
}
	
int sub(int x, int y) {
    return x-y;
}

int main() {
    int i;
    fp[0] = add;
    i = (*fp[0])(10,20);      // calling add function
    printf("add: %d \n",i);
    fp[1] = sub;
    i = (*fp[1])(20,10);      // calling sub function
    printf("sub: %d \n",i);
    return 0;
}