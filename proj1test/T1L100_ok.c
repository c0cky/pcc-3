/* There are no errors in this file! */

void a();
int b();
double c();
int d(int a);
float e(unsigned char a);
short f(double a);
double g(long a, double b);
void h(int a, unsigned b, double c);

/* Pointer, array, and function types as parameters */
void i(int *a);
float j(int a[5]);
long k(char (*f)());
unsigned short int l(unsigned char **a, long b[5], double *c());


/* Reference parameters */
void m(int& a);
int n(int *& x);
int o(double& a, double& b, int c);
void p(int a, int& b, int (&c)[4], double (&d)(), char *(&e)());
