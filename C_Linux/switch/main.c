#include<stdio.h>
int main() {
    int a = 2;
    switch(a) {
       case 1:
          printf("this is date\n");
          break;
       case 2:
          printf("this is month\n");
          break;
       case 3:
          printf("this is year\n");
          break;
       default:
          printf("This is default case\n");
   }
   return 0;
}