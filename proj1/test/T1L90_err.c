
/* some type specifier combinations */

signed int a;
int unsigned b;
long unsigned int c;
short d;

/* some illegal ones */

short short e;
short float f;
signed double g;

/* functions */

int h();
double i();

/* modifier combinations */

int *j();
int (*k)();
int (*l[10])();

/* illegal functions */

int m()();
float n()[3];
double o[5]();


