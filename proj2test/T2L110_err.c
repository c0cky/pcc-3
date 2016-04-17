
/* test file for extra credit level of project part 2, CSCE 531 */

/* there are errors in this file */

int i,j,k,f();

float x,y,z;

double d;

char c;

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

        /* some errors involving inc and dec operators */
    j = --i++;
    i = j++--;
    j = ----i;
    3++;
    i++ = j;
    (i=j)++;
    main++;
	
    f(c);
}

f(int c)
{
    int i;

    i = 19;
    {
        int i;

        i = k;
    }
    {
        float i;

        i = d;
    }

    i = i + 1;
}

g(char c)
{
    int c;
    float x;
    double d;
    int g;
    int x;

    {
        int u;
        float i,u;

        d = i;
    }

    c = c;
}


