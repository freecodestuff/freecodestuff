#include<stdio.h>
int main() {
        int *i;
        char *c;
        double *d;
        float *f;
        long long int *lli;

        printf(" %lu ",sizeof(i));
        printf(" %lu ",sizeof(c));
        printf(" %lu ",sizeof(d));
        printf(" %lu ",sizeof(f));
        printf(" %lu\n",sizeof(lli));
        return 0;
}