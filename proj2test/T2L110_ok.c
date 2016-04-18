
/* test file for extra credit level of project part 2, CSCE 531 */

/* there are no errors in this file */

int i,j,k;
float x,y,z;
double d;
char c;

int printf();
int f();
int g();


main()
{
    int i;
    float x,y;

    k = 19;
    d = k * 2;
    c = k;

    i = k;
    x = i;
    y = d;

    i++;
    j = i++;
    j = ++i;
    x--;
    printf("c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           c, d, i, j, k, x, y);

    f(c);

    printf("c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           c, d, i, j, k, x, y);

    g(3);
}

f(int c)
{
    int i;

    i = 19;
    printf("c = %d; i = %d\n", c, i);

    {
        int i;

        i = k;
        printf("c = %d; i = %d\n", c, i);
    }

    printf("c = %d; i = %d\n", c, i);

    {
        float i;

        i = d;
        printf("c = %d; i = %e\n", c, i);
    }

    i = i + 1;
    printf("c = %d; i = %d\n", c, i);
}

g(char c)
{
    float x;
    double d;

    c = c + 11;

    {
        int u;
        float i;

        i = 3.14;
        d = i;
    }

    c = c;

    printf("c = %d; d = %lg\n", c, d);
}
