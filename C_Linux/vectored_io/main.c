#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>

int main() {
    int fd, fi, i;
    char *d[] = {"India.\n","Blog.\n"},a[10],b[10];
    struct iovec buf[2], buff[2];
    fd = open("buf.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
    if(fd < 0) {
        printf("open error\n");
        return -1;
    }
    for(i=0;i<2;i++){
    buf[i].iov_base = d[i];
    buf[i].iov_len = strlen(d[i])+1;
    }
    writev(fd,buf,2);
    close(fd);
    fi = open("test.txt",O_RDONLY);
    if(fi < 0) {
        printf("open error\n");
        return -1;
    }
    buff[0].iov_base = a;
    buff[0].iov_len = sizeof(a);
    buff[1].iov_base = b;
    buff[1].iov_len = sizeof(b);
    readv(fi,buff,2);
    for(i=0;i<2;i++) {
        printf("%s\n",(char *)buff[i].iov_base);
    }

    close(fi);
    return 0;
}