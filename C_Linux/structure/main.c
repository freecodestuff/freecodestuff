#include<stdio.h>
struct s {
	int a;
	int b;
};

void fun(struct s *x ,struct s  *y,struct s *sum)
{
	sum->a = x->a + y->a;
	sum->b = x->b + y->b;
}
int main()
{
	struct s obj1 ={10,10.8}, obj2 = {20, .2}, obj3;
	fun(&obj1, &obj2, &obj3);
        printf("size of %ld\n", sizeof(struct s));
	printf("%d %d", obj3.a,obj3.b);

	return 0;
}