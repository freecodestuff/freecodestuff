#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

struct student{
        char name[25];
        int no;
        char gen;
};

int main() {
        int fd, ret, i;
        struct student s[3] = {{"satheesh",1,'m'},{"kumar",2,'m'},{"nelavalli",3,'m'}};
        struct student rs[3];
        fd = open("file.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
        if(fd < 0) {
                perror("open");
                return -1;
        }
        ret = write(fd,s, sizeof(s));
        if(ret < 0) {
                perror("write");
                return -1;
        }
        lseek(fd, 0, SEEK_SET);
        ret = read(fd, rs, sizeof(rs));
        if(ret < 0) {
                perror("read");
                return -1;
        }
        for(i=0; i<3;i++) {
                printf("%s %d %c \n", rs[i].name, rs[i].no,rs[i].gen);
        }
        close(fd);
        return 0;
}