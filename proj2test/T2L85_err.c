/* test file for 85% level of project part 2, CSCE 531 */

/* there are errors in this file! */

int i,j,k;

float x,y,z;

double d, get_doub();

char c;

void print_globals();
int get_int();
float get_doub();

main()
{
    print_globals();	/* link in print_globals later */

    i = 5;		
    j = i;
    d = 19.1999;

    print_globals();

    k = i + j;		
    j = i - k * k / (i + k);
    i = k > j;
	
    print_globals();

    x = y = k;
    d = k;
    c = k;
    z = c * i + (-d) - x;
    c = (x < (i = 19));

    print_globals();

    i = get_int() + 9; 		/* get_int also linked in */
    d = get_doub() + 9.9; 	/* get_doub also linked in */

    xyz();
}

double w()
{
}

char w()
{
}

float x()
{
}

int xyz()
{
    i = 1999;

    print_globals();
}

int abc()
{
    q = 19;
    c();
    abc = 19;
}

int fold()
{
    i = 99 + 17;
    d = -19.99;
    i = 99 * 17.76;
}
	
