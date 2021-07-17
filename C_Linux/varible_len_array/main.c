#include<stdio.h>
int main() {
     int size =5;
     int arr[size],i=0;
     for(i=0; i< size; i++) {
         arr[i] = i+2;
     }
     for(i=0; i< size; i++) {
         printf("%d ",arr[i]);
     }
     return 0;
}