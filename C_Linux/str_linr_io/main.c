#include<stdio.h>
int main() {
        FILE *fp;
        char str[60];
        //fputs example
        fp = fopen("file.txt","a+");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        fputs("kumar",fp);
        fclose(fp);
        //fgets example
        fp = fopen("file.txt","r");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        if(fgets(str,60,fp) != NULL) {
                printf("%s ", str);
        }
        printf("\n");
        fclose(fp);
        //fprintf example
        fp = fopen("file.txt","a+");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        fprintf(fp,"%s %d", "nelavalli", 2021);
        fclose(fp);
        //fscanf exmple
        char str1[30], str2[30], str3[30];
        fp = fopen("file.txt","a+");
        if(fp == NULL) {
                printf("fopen error\n");
                return -1;
        }
        fscanf(fp, "%s %s %s", str1,str2,str3);
        printf("%s %s %s \n",str1, str2, str3);
        fclose(fp);
        return 0;
}