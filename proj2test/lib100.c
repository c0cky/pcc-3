#include <stdio.h>

extern int ga, gd;
extern float gb;
extern double gc;
extern char ge;

/* Simulate reference parameters in C with pointers */
extern ref_params(char* a, int* b, float* c, double* d, int* e);

print_g()
{
    printf("print_g: ga = %d; gb = %f; gc = %lf; gd = %d; ge = '%c' (%d)\n",
           ga, gb, gc, gd, ge, ge);
}

/* Our parameter conversions are for traditional C, but lib100.c is
 * compiled as standard C, where floats are passed in as floats (not
 * doubles). We pass a double as 2nd arg to this function (converted
 * from a float), so explicitly demand a double as 2nd parameter.
 */
print_p(int a, double b, double c, int d, int e)
{
    float f = b; /* Down-convert "by hand" */
    
    printf("print_p: a = %d; b = %f; c = %lf; d = %d; e = '%c' (%d)\n",
           a, f, c, d, e, e);
}

test_ref_params()
{
    ref_params(&ge, &ga, &gb, &gc, &gd);
}
