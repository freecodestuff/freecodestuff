#include<stdio.h>
#include<string.h>
union x {
    int a;
    char name[256];
};

int main()
{
	union x obj;
	printf("sizeof union %ld\n", sizeof(union x));
	strcpy(obj.name,"satheesh");
	printf("%s \n", obj.name);

	return 0;
}