int i, j, *pi, **ppi;

float f, *pf;

char c , *s1, *s2;

int ***pppi;

int print_ints(), print_floats();


main()
{

	i = 19;
	j = 28;
	pi = &i;
	ppi = &pi;
	j = i + *pi;
	print_ints();
	*pi = j;
	print_ints();
	j = *pi * **ppi;
	print_ints();
	
	f = 199;
	pf = &f;
	/*	*pf = *pf / (*pf + 1);	*/
	print_floats();
	
	
}


