#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main() {
        int fd, ret;
        char *wrbuff = "Welcome to my Blog";
        fd = open("abc.txt",O_WRONLY|O_SYNC|O_CREAT,0666);
        if(fd < 0) {
                printf("open error\n");
                return -1;
        }
        ret = write(fd, wrbuff, strlen(wrbuff));
        getchar();
        getchar();
        ret = write(fd, wrbuff, strlen(wrbuff));
        getchar();
        getchar();
        close(fd);
        return 0;
}