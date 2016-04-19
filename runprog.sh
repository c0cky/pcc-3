#!/bin/bash
make clean
make
./pcc3 < T2L85_ok.c > t.s
gcc -m32 t.s lib85.c
./a.out
