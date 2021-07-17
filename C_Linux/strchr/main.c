#include<stdio.h>
#include<string.h>

int main() {
        char str[10] = "satheesh";
        char *st = strchr(str, 'e');
        printf("%s %s \n", str, st);
        return 0;
}