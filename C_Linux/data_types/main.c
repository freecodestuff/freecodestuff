#include<stdio.h>
int main() {
        int i;
        char c;
        double d;
        float f;
        long long int lli;
        long double ld;
        short int si;
        long int li;

        printf(" %lu ",sizeof(i));
        printf(" %lu ",sizeof(c));
        printf(" %lu ",sizeof(d));
        printf(" %lu ",sizeof(f));
        printf(" %lu ",sizeof(lli));
        printf(" %lu ",sizeof(ld));
        printf(" %lu ",sizeof(si));
        printf(" %lu\n",sizeof(li));
        return 0;
}