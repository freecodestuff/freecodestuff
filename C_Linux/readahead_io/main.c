#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main()
{
	char buff[512];
	int f = open("text.txt", O_RDONLY);
	posix_fadvise(f, 20,20,POSIX_FADV_RANDOM);
    read(f,buff,512);
	buff[512] ='\0';
	printf("%s \n", buff);
	close(f);
	return 0;
}