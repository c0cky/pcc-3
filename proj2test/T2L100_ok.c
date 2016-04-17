
/* test file for 100% level of project part 2, CSCE 531 */

/* there NO are errors in this file */

int i,j,k;

float x,y,z;

double d;

char c;

int test_ref_params();
int print_g();
int print_p();
int printf();
int f();

main()
{
    i = 34;
    k = 5;
    x = i / k;
    d = x * 2;
    c = i;
    c = c + 50;
    f(i,x,d,c,c);
    print_g();
    test_ref_params();
    print_g();
    printf("this is a debugging message\n");
}

int ga;
int gd;
float gb;
double gc;
char ge;

f(int a, float b, double c, int d, char e)
{
    ga = a;  /* ga == 34 */
    gb = b;  /* gb == 6.0 (not 6.8 --- believe it!) */
    gc = c;  /* gc == 12.0 */
    gd = d;  /* gd == 84 */
    ge = e;  /* ge == 'T' */

    print_g();

    b = b + c + d + a + e;

    print_p(a,b,c,d,e);
    print_p(a*1,b+c,b+(c==d),d,d==e);
}

/* Testing reference parameters (called from test_ref_params() in lib100.c) */

ref_params(char& a, int& b, float& c, double& d, int &e)
{
        /* Effectively swaps b and e */
    b = e - b;
    e = e - b;
    b = e + b;
        /* Effectively swaps c and d */
    d = c - d;
    c = c - d;
    d = c + d;

    a = a + 6;
}
