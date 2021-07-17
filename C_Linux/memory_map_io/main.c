#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <sys/stat.h>

int main() {
        int fd;
        unsigned char *filedata = NULL, *tmp;
        fd = open("test.txt", O_RDWR);
        struct stat fileInfo = {0};

        if (fstat(fd, &fileInfo) == -1)
        {
                perror("Error getting the file size");
                return -1;
        }
        if (fileInfo.st_size == 0)
        {
                printf("Error: File is empty\n");
                return -1;
        }
        filedata = mmap(NULL, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if(!filedata) {
                perror("mmap");
                close(fd);
                return -1;
        }
        printf("%s", filedata);

        if (munmap(filedata, fileInfo.st_size) == -1)
        {
                close(fd);
                perror("munmap");
                return -1;
        }
        close(fd);
        return 0;
}