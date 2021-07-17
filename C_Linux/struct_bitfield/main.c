#include <stdio.h>
#include <string.h>

struct x{
        int w;
        int h;
};


struct y{
        int w : 1;
        int h : 1;
};

int main( ) {
        printf( "size of struct x : %ld\n", sizeof(struct x));
        printf( "size of struct y : %ld\n", sizeof(struct y));
        return 0;
}