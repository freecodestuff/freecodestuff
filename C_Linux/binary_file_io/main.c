#include<stdio.h>
#include<string.h>
int main() {
        FILE *fp;
        char str[20] = "Welcome to India";
        char buf[20];
        //fwrite example
        fp = fopen("file2.txt","w+");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        fwrite(str,strlen(str)+1, 1, fp);
        fclose(fp);
        //fread example
        fp = fopen("file2.txt","r");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        fread(buf, strlen(str)+1, 1, fp);
        printf("%s \n", buf);
        fclose(fp);
        return 0;
}