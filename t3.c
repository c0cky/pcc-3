/* Test file for Project III, 80% level, CSCE 531 */

/* There are no errors in this file. */

int i,j;

int f1(), f2(), f3(), f4(), f5();

main()
{
    f1();
    f2();
    f3();
    f4();
    f5();
}

int a,b,c;
int print_abc();

f1()  {

    a = 1;
    b = 1;
    c = 1;

    while (b < 99) {

        if (a > 9) {
            b = b * 2;
            a = a + 3;
        } else {
            b = b * 3;
            a = a * 2;
        }

        print_abc();
        c = c+1;

    }

}

int x;
int print_x();

f2() {

    x = 9;

    while (1) {
        if (x < 0) break;
        print_x();
        x = x - 1;
    }

}

int nine()
{
    return 9;
}

f3() {
    x = nine();
    print_x();
}

float f()
{
    return nine() * nine();
}

float z;
int print_z();

f4()
{
    z = f();
    print_z();
}


int nine2()
{
    if (x) return 9;
    else return z + 19;
}

f5() {
    x = 0;
    z = nine2();
    print_z();
    x = 1;
    z = nine2();
    print_z();
}
