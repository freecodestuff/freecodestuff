#include <stdio.h>

int main()
{
	#ifdef INPUT
		int i;
                i=2;
                printf("%d\n",i);
	#else	
		int i;
                printf("Enter a value\n");
                scanf("%d",&i);
                printf("%d\n",i);
	#endif
}