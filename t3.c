/* Test file for Project III, 80% level, CSCE 531 */

/* There are no errors in this file. */

int i,j;

int f1(), f2(), f3(), f4(), f5(), f6(), f7(), f8(), f9();

main()
{
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
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

int print_oops(), print_7(), print_1(), print_2(), print_newline();
int print_is(), print_awesomest_nl();

f6() {

    a = 0-1;
    b = 0;
    c = 1;

    if (a > b) {
        print_oops();
    } else {
        if (b == (c+a))  {
            print_7();
            print_1();
            if (1) print_2();
            print_newline();
        } else {
            print_oops();
        }
        print_is();
    }

    print_awesomest_nl();

}

int print_outer(), print_inner(), print_inner_inner();

f7() {

    a = 0-1;

    while (a > 3) {
        print_oops();
    } 

    while (a < 3) {

        print_outer();

        b = 0;
        while (b < (a+1)) {
            print_inner();
       
            c = 0;
            while (c < 0) {
                print_inner_inner();
                c = c+1;
            }

            b = b+1;
        }

        a = a+1;
    } 

}

int print_looping();

f8() {

    x = 9;

    while (1) {
        if (x < 0) break;
        print_looping();
        x = x - 1;
    }

    if (x) {
        x = 0;
    }
}

int print_looping_looping(), print_looping_looping_looping();

f9() {

    x = 3;

    while (1) {
        if (x < 0) break;
        print_looping();
        b = 0;

        while (1) {
            if (b > 1) break;
            print_looping_looping();
            c = 8;

            while (1) {
                if (c > 10) break;
                print_looping_looping_looping();
                c = c+1;
            }
            b = b + 1;
        }
        x = x - 1;
    }

}
