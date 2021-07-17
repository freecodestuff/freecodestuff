#include<stdio.h>
#define VAL(x,y) x##y
int main(){
        printf("%d\n",VAL(10,30));
        return 0;
}