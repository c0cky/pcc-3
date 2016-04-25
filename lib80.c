/* Print "library" for 80% level of Project Part 4, CSCE 531 */

#include <stdio.h>

extern int i, j, *pi, **ppi;


print_ints()
{
    printf("i = %d; j = %d; pi-&i = %x; ppi-&pi = %x\n", i, j, pi-&i, ppi-&pi);
}

