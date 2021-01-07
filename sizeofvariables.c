#include <stdio.h>

int main()
{
int a = 545;
printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

char k = 'b';
printf("char k: %c and size: %lu bytes\n", k, sizeof(k));

float f = 17.777;
printf("float f: %f and size: %lu bytes\n", f, sizeof(f));

double d = 777.888;
printf("double d: %f and size: %lu bytes\n", d, sizeof(d));

long l = 6666;
printf("long l: %d and size: %lu bytes\n", l, sizeof(l));

short s = 55;
printf("short s: %d and size: %lu bytes\n", s, sizeof(s));
}
