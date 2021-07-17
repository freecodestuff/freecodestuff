#include<stdio.h>

int main() {
        char str[10] = "satheesh";
        printf("%s\n", str);
        
        char n[] = "nelavalli";
        char *p = n;
        printf("%ld %ld \n", sizeof(p), sizeof(*p));
        return 0;
}