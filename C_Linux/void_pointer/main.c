#include <stdio.h>

int main()
{
    int a = 10;
    void *p;
    p = &a;
    *(int *)p = 100;
    printf("%d %d", a, *(int *)p);

    return 0;
}