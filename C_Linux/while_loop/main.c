#include<stdio.h>
int main(){
    int a = 0,i = 0;
    while( i < 5) {
       a = a+i;
       i++;
    }
    printf("%d \n", a);
    return 0;
}