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
long j(char (*f)());
unsigned short int k(unsigned char **a, long b[5], double *c());


/* Reference parameters */
void j(int& a);
int k(int *& x);
int k(double& a, double& b, int c);
void l(int a, int& b, int (&c)[4], double (&d)(), char *(&e)());
