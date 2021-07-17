#include <stdio.h>
void add_sub(int a, int b, int *p, int *q){
    *p = a+b;
    *q = a-b;
}
int main()
{
    int x = 20, y=10, sum, diff;
    add_sub(x,y,&sum,&diff);
    printf("sum:%d diff:%d \n", sum,diff);

    return 0;
}