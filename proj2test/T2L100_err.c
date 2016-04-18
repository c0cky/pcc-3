
/* test file for 100% level of project part 2, CSCE 531 */

/* there are errors in this file */

int i,j,k;

float x,y,z;

double d;

char c;

int f();
int printf();
int print_g();
int print_p();

main()
{
    i = 19;
    k = 22;
    x = i / k;
    d = x * 2;
    c = i;
    f(i,x,d,c);
    printf("this is a debugging message\n");
}

int ga;
int gd;
float gb;
double gc;

f(int a, float b, double c, int a)
{
    ga = a;
    gb = b;
    gc = c;
    gd = 0;

    print_g();

    b = b + c + a;

    print_p(a,b,c,d);
    print_p(a*1,b+c,c==d,d);
}

void h(int a, double b, float b, char c, int c)
{
}
