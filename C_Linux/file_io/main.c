#include<stdio.h>

int main() {
        FILE *fp1,*fp2;
        char c;
        fp1 = fopen("./file.txt","r");
        if(fp1 == NULL) {
                printf("Unable to open file\n");
                return -1;
        }
        fp2 = fopen("./file1.txt","w");
        if(fp2 == NULL) {
                printf("Unable to open file\n");
                return -1;
        }
        while((c = fgetc(fp1)) != EOF) {
                fputc(c,fp2);
                printf("%c", c);
        }
        fclose(fp2);
        fclose(fp1);
        return 0;
}