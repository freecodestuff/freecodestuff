#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BLOCKSIZE 512
char s[512] = "The function posix_memalign() allocates size bytes and places the address of the allocated memory in *memptr. The address of the allocated memory will be a multiple of alignment, which must be a power of two and a multiple of sizeof(void *). If the size is 0, then posix_memalign() returns either NULL or a unique pointer value that can later successfully pass to free(3) The function posix_memalign() allocates size bytes and places the address of the allocated memory in *memptr. The address of the allocated  ";
int main()
{
        void *buffer;
        posix_memalign(&buffer, BLOCKSIZE, BLOCKSIZE);
        memcpy(buffer, s, BLOCKSIZE);
        int f = open("text.txt", O_CREAT|O_TRUNC|O_WRONLY|O_DIRECT, S_IRWXU);
        write(f, buffer, BLOCKSIZE);
        close(f);
        free(buffer);
        return 0;
}