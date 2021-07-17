#include<stdio.h>
int main(int argc, char *argv[])
{
        int i;
        printf("%d \n", argc);
        if( argc >= 2 )
        {
                for(i = 0; i < argc; i++)
                {
                        printf("%s ", argv[i]);
                }

                printf("\n");
        }
        else
        {
                printf("you didn't pass any arguments\n");

        }
        return 0;
}