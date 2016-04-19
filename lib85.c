#include <stdio.h>

extern int i,j,k;
extern float x,y,z;
extern double d;
extern char c;

print_globals()
{
  printf("i = %d; j = %d; k = %d\n", i, j, k);
  printf("x = %f; y = %f; z = %f\n", x, y, z);
  printf("d = %lf\nc = %d\n", d, c);
}

int get_int()
{
  int ret;

  printf("Enter an integer:  ");
  scanf("%d", &ret);

  return ret;
}

double get_doub()
{
  double ret;

  printf("Enter a double:    ");
  scanf("%lf", &ret);
  return ret;
}

