#include<stdio.h>
#include<string.h>

int main() {
        char str[10] = "satheesh";
        char st[10] = "kumar";
        strcat(str, st);
        printf("%s %s \n", str, st);
        return 0;
}