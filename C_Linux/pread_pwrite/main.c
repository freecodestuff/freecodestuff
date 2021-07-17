#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>

int main()
{
        int fd,ret;

        char buf[20];

        pid_t pid;
        off_t offset = 0;
        fd = open("./test.file",O_RDWR);
        if(fd < 0){
                perror("open");
                exit(1);
        }
        printf("new file descriptor :%d\n",fd);

        pid = fork();

        if(pid == 0){
                ret = pwrite(fd,"Welcome to India",16,offset);
                if(ret < 0)
                        perror("child write:");

                ret = pread(fd,buf,4,offset);
                if(ret < 0)
                        perror("child read:");
                buf[ret] = '\0';
                printf("In child:%s\n",buf);

                close(fd);
                ret = pread(fd,buf,4,offset);
                if(ret < 0)
                        perror("child read:");
        }
        else{
                wait(NULL);
                ret = pread(fd,buf,10,offset);
                if(ret < 0)
                        perror("parent read:");
                buf[ret] = '\0';
                printf("In parent:%s\n",buf);
        }

        return 0;
}