#include<stdio.h>
int main() {
    int a = 5;
    struct x {
        int q;
        char w;
    };
    char d;
    int arr[] = {1,2,3,4,5};
    printf("%ld %ld %ld %ld \n", sizeof(a), sizeof(struct x), sizeof(d), sizeof(arr));
    return 0;
}