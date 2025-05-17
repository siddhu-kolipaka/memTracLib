#include<stdio.h>
#include"memtrac.h"

int main()
{
int *x;
x = (int *)my_malloc(2,7);
report();
int *y = (int *)my_malloc(4,8);
report();
my_free(y);
report();
return 0;
}
