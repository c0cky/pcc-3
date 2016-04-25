int i, j, *pi, **ppi;

int print_ints();

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
	/*j = *pi * **ppi;*/
	print_ints();
}
