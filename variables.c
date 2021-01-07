#include <stdio.h>

int main()
{
int a;
int b = 3;
int c;
a = 2;
c = a + b;
 
printf("Sum of %d and %d is %d\n", a, b, c);
 int t = a;
 a = c;
 c = t;
 
 printf("Difference of %d and %d is %d after the swap\n", a, b, c);
}
