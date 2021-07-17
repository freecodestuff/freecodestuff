#include<stdio.h>
int main() {
   int x = 2;
   x += 2;
   printf("%d ", x);
   x -= 2;
   printf("%d ", x);
   x *= 2;
   printf("%d ", x);
   x /= 2;
   printf("%d ", x);
   x %= 2;
   printf("%d ", x);
   x &= 2;
   printf("%d ", x);
   x ^= 2;
   printf("%d ", x);
   x |= 2;
   printf("%d ", x);
   x <<= 2;
   printf("%d ", x);
   x >>= 2;
   printf("%d ", x);
   return 0;
}