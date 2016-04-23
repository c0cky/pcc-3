/* Library file for Project III (all levels), CSCE 531 */

#include <stdio.h>

extern int a,b,c;

print_abc()
{
	printf("a = %d; b =  %d; c = %d\n",a,b,c);
}

extern int x;

print_x()
{
	printf("x = %d\n",x);
}


extern float z;

print_z()
{
	printf("z = %e\n",z);
}
