#include<stdio.h>
#include<string.h>
int main() {
        char str[10] = "satheesh";
        char st[10] = "satheesh";
        int i = strcmp(str, str);
        printf("%d \n", i);
        return 0;
}