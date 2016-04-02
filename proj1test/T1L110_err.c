
/* the basic cases */

int i = 19;
float x = 19.19;
double d = 21.21;
char c = 0;
int *p = 0;
int **pp = 0;

/* try arrays */

int ai[10] = {0,1,2,3,4,5,6,7,8,9};

float ax[5] = {1.1,1.2,2.3,1.4,1.5};

double ad[4] = {3.3,4.4,5.5,6.6};

/* incomplete arrays */

int icai[10] = {5,5,5,5,5};

/* multi-d arrays */

int mdai[3][5] = { {0,1,2,3,4}, {6,7,8,9,10}, {11,12,13,14,15} };

int mdai2[3][5] = { {0,1,2,}, {6,7,8,9,10}, {12,13,14,15} };

/* some errors */

int e1[3] = {0,1,2,3};

int e2 = 19.9;

int e3 = {0,1};

int e4[2][2] = {{0,1},{2,3,4}};

int e5[2][2] = {{0,1},{2,3},{4,5}};

