#include<stdio.h>
#include<string.h>

int main() {
        char str[10] = "satheesh";
        char st[10];
        strcpy(st, str);
        printf("%s %s \n", str, st);
        return 0;
}